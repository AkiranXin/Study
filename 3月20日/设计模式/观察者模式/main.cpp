#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void Update() = 0;
};

class Blog
{
private:
    list<Observer* > observer_lists;
protected:
    string _status;
public:
    Blog(){}
    virtual ~Blog(){}
    void Attach(Observer* observer){ observer_lists.push_back(observer);}
    void Remove(Observer* observer){ observer_lists.remove(observer);}
    void Notify()
    {
        for(auto iter : observer_lists)
        {
            iter->Update();
        }
    }
    virtual void SetStatus(const string status){ _status = status;}
    virtual string GetStatus() const{ return _status;}
};

class BlogWordPress : public Blog
{
private:
    string Bloger_name;
public:
    BlogWordPress(string name) : Bloger_name(name){}
    ~BlogWordPress(){}
    void SetStatus(const string status){ _status = "WordPress " + status + " Bloger: " + Bloger_name;}
    string GetStatus() const{ return _status;}
};

class BlogObserver : public Observer
{
private:
    string Ob_name;
    Blog* _blog;
public:
    BlogObserver(string name, Blog* Blog) : Ob_name(name), _blog(Blog){}
    ~BlogObserver(){}
    void Update()
    {
        string status = _blog->GetStatus();
        cout << "Observer: " << Ob_name << " is watching ---" << status << endl;
    }
};



//测试案例
int main()
{
    Blog* blog = new BlogWordPress("Akiran");
    Observer* ob_1 = new BlogObserver("DreaminNamae", blog);
    blog->Attach(ob_1);
    blog->SetStatus("Now has been published!");
    cout << blog->GetStatus() << endl;
    blog->Notify();
    delete blog;
    delete ob_1;
    return 0;
}
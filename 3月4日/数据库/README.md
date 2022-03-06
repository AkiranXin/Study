### 主键
> 表示每一行（记录）都应该有唯一标识自己的一列（或一组列）。
> > 应该总是定义主键：
> 没有主键，更新或删除表中特定行会很困难，因为没有相关办法能够保证只涉及相关的列W

### 外键
> 外键为某个表中的一列，它包含另一个表的主键值

例如：假设有一个供货商生产了多种产品，如何存储？将供应商信息和商品信息分开存储的理由（好处）如下：
* 同一供应商的信息应该是相同的，不需要每个商品都去存储供应商信息浪费存储空间
* 如果供应商信息改变，则只需要更改供应商的信息就行
* 如果合并存储，则难以保证每次输入该数据的方式相同。如果数据无重复，则数据是一致的，数据处理会更简单

```
SHOW COLUMNS FROM vendors;（供货商）
+--------------+----------+------+-----+---------+----------------+
| Field        | Type     | Null | Key | Default | Extra          |
+--------------+----------+------+-----+---------+----------------+
| vend_id      | int(11)  | NO   | PRI | NULL    | auto_increment |
| vend_name    | char(50) | NO   |     | NULL    |                |
| vend_address | char(50) | YES  |     | NULL    |                |
| vend_city    | char(50) | YES  |     | NULL    |                |
| vend_state   | char(5)  | YES  |     | NULL    |                |
| vend_zip     | char(10) | YES  |     | NULL    |                |
| vend_country | char(50) | YES  |     | NULL    |                |
+--------------+----------+------+-----+---------+----------------+


SHOW COLUMNS FROM products;（产品）
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| prod_id    | char(10)     | NO   | PRI | NULL    |       |
| vend_id    | int(11)      | NO   | MUL | NULL    |       |
| prod_name  | char(255)    | NO   |     | NULL    |       |
| prod_price | decimal(8,2) | NO   |     | NULL    |       |
| prod_desc  | text         | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+

```
> 可以用外键的形式，指定每个商品对应的供货商id，则可以通过供货商id来访问供货商
---
### 登录MySQL
```SHELL
mysql -u root -p ******
```
> -u(user):指定用户
> -p: 使用密码
---
一般MySQL端口号为3306

---
### MySQL使用
```
SHOW DATABASES;//显示所有数据库

USE [DATABASE_NAME];//使用指定数据库

SHOW TABLES;//显示数据库中所有表

SHOW COLUMNS FROM [TABLE_NAME];//显示指定表中结构
```
---
#### 检索语句(SELECT)
1. 检索单个列
```
SELECT prod_name FROM products;//从products表中查询列名为prod_name的列
```
2. 检索多个列
```
//从products表中查询prod_id, prod_name, prod_price的列

SELECT prod_id, prod_name, prod_price FROM products;
```
3. 检索所有列
> 使用通配符(*)
```
SELECT * FROM products;
```
4. 检索不同的列
> 使用关键字 DISTINCT
```
SELECT DISTINCT vend_id FROM products;
```
5. 限制检索结果
> 使用关键字 LIMIT
```
//返回查询结果中的前五列
SELECT prod_name FROM products LIMIT 5;

//返回查询结果中从第五列开始的后五列
SELECT prod_name FROM products LIMIT 5,5
```
* 参数为一个值的，就是说前几行
* 参数为两个值的，一个列中的第一行称为行0，则LIMIT 1,1。会返回第二行所以基本上按照数组的方式来理解下标就行

---
#### 排序数据
使用ORDER BY
```
SELECT prod_name FROM products ORDER BY prod_name;//默认为升序排序(ASC)

SELECT prod_name FROM products ORDER BY prod_name DESC;//降序排序

SELECT prod_id prod_price prod_name FROM products
ORDER BY prod_price, prod_name;//多个列排序
// 仅在 多个行具有相同的prod_price时才对prod_name进行排序
```
---
#### 过滤数据
##### 1. WHERE子句
例如
```
SELECT prod_name, prod_price FROM products WHERE prod_price = 2.50;
```
其他 = 、>=、!=之类的和c/c++的差不多,都是通用的

* 范围值检查(BETWEEN AND)
* 空值检查(IS NULL)

##### 2. AND操作符（和） OR操作符(或)
```
//返回vend_id为1003的且prod_price小于等于10的行
SELECT prod_id, prod_price, prod_name
FROM products
WHERE vend_id = 1003 AND prod_price <= 10;

//返回vend_id为1002或者vend_id为1003的行
SELECT prod_name, prod_price
FROM products
WHERE vend_id = 1002 OR vend_id = 1003;
```
##### 3. 计算次序 “（）”
次序就是从左到右，使用（）可以改变次序
比如p1 OR p2 AND p3，则效果越等于为 p1 OR (p2 AND p3)

##### 4.IN操作符
结合使用括号()，可以指定范围
```
SELECT prod_name, prod_price
FROM products
WHERE vend_id IN (1002, 1003)
ORDER BY prod_name;//取值vend_id为1002到1003的行
//你会发现这个效果约等于1002 OR 1003
```
你也可以添加NOT操作符，来反向指定，比如我不要1002和1003的行
只需要变成 NOT IN(1002, 1003)即可

---
### 通配符
通配符就是用来匹配值得特殊字符，使用通配符要搭配LIKE操作符

##### 1. %通配符
%表示任何字符出现任何次数
```
SELECT prod_id, prod_name FROM products WHERE prod_name LIKE 'jet%';
+---------+--------------+
| prod_id | prod_name    |
+---------+--------------+
| JP1000  | JetPack 1000 |
| JP2000  | JetPack 2000 |
+---------+--------------+
```
##### 2. _下划线通配符
和%一样，只不过时单个字符

> 不要过度使用通配符，能用其他操作符做到的就别用

---
### 正则表达式

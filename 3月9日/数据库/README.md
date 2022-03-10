### 正则表达式
##### 匹配多个实例
|元字符|说明|
|---|---|
|*|0个或多个匹配|
|+|1个或多个匹配（等于{1,}）|
|?|0个或1个匹配|
|{n}|指定数目的匹配|
|{n,}|不少于指定数目的匹配|
|{n,m}|匹配数目的范围（m不超过255）|

例子：
```
SELECT prod_name
FROM products
WHERE prod_name REGEXP '\\([0-9] sticks?\\'
ORDER BY prod_name
```
> 返回结果
> prod_name
> TNT (1 stick)
> TNT (5 sticks)

##### 定位符
* 文本的开始*
* 文本的结尾$

> LIKE匹配整个串而REGEXP匹配子串，利用定位符可以让REGEXP类似于LIKE

---

## 创建计算字段

### 使用MySQL正则表达式
1. 基本字符匹配
```
SELECT prod_name 
FROM products 
WHERE prod_name REGEXP '.000' 
ORDER BY prod_name;
```
这里和之前用通配符匹配有点相像，LIKE替换为REGEXP
* .表示匹配任意一个字符
> LIKE和REGEXP的区别
```
SELECT prod_name
FROM products
WHERE prod_name LIKE '1000'
ORDER BY prod_name;

SELECT prod_name
FROM products
WHERE prod_name REGEXP '1000'
ORDER BY prod_name;
```
> 执行上述语句，第一个命令不返回数据，而第二条语句返回一行
> 因为第一条语句虽然用的是LIKE但是并没有搭配通配符，则就算找到了也会跳过并且不返回
---
2. 进行OR匹配
```
SELECT prod_name
FROM products
WHERE prod_name REGEXP '1000|2000'
ORDER BY prod_name;
```
3. 匹配几个字符之一
```
SELECT prod_name
FROM products
WHERE prod_name REGEXP '[123] Ton'
ORDER BY prod_name;
```
[123]为[1|2|3]缩写
[^123]为排除123，匹配除这几个以外的任意字符

4. 匹配特殊字符
```
SELECT vend_name 
FROM vendors 
WHERE vend_name REGEXP '\\.'
ORDER BY vend_name;
```
在MySQL中转义字符\\，因为还要匹配\自己
5. 
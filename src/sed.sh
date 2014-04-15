#!/bin/sh

FILE_ARR=`ls $1 |grep -E '[0-9]_[0-9]{1,2}.c'`
for filename in $FILE_ARR;do
	sed  -i 's/\.\.\/apue\.h/apue\.h/g' $1/$filename 
done

#!/bin/bash
a="Apple Pie"
new="Juice"
echo ${a/${a:6:3}/$new}

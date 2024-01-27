# Project 1: Password Strengthener
TO RUN STRENGTHER PROGRAM: 
```
python3 strength.py <path-to-rockyou.txt.6.1.1>
 ```


output will be:
 <path-to-rockyou.txt.6.1.1>.strength

Make sure  <path-to-rockyou.txt.6.1.1>.strength, rockyou.txt.6.4.a.pcfg1, pcfgc, pwdstats, crack-file are present in the /password_cs165 then run:
```
./pcfgc 1 rockyou.txt.6.1.a.strength  rockyou.txt.6.4.a.pcfg1 > crack-file
./pwdstats < crack-file
```


 # Example
```
python3 strength.py /home/csmajs/drios027/rockyou.txt.6.1.a
./pcfgc 1 rockyou.txt.6.1.a.strength  rockyou.txt.6.4.a.pcfg1 > crack-file
./pwdstats < crack-file
```

import sys
from collections import Counter
import random

#Most common structure: U1L5S1D1 (282)
'''TO RUN: python3 strength.py <path-to-rockyou.txt.6.1.a>
   after code will export rockyou.txt.6.1.a.strength 
'''

def process(path):
    with open(path, 'r') as p:
        passwords = p.read().splitlines()
    altered = [strength(pwd) for pwd in passwords]

    path_name = path.split('/')
    with open(f'{path_name[4]}.strength','w')as f:
        for line in altered:
            f.write(f"{line}\n")

def strength(pwd):
    Upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' # U - Upper
    Lower = 'abcdefghijklmnopqrstuvwxyz' # L - Lower
    Special = '!@#$%^&*()_+' # S - Special
    Q = 'Qq'
    Num = '0123456789' # D - number
    #print(pwd)
    pass_list = list(pwd) 
    randlist = [1, 2, 5]
    if len(pass_list) == 6: #S1U1L1U1D2
        pass_list[2] = random.choice(Q)
        pass_list[5] = random.choice(Q)
        pass_list[random.choice([0,1])] = random.choice(Q)    
        
    if len(pass_list) == 7: #U1S1L2D1L1D1, L2D1U1L2S1
        pass_list[1] = random.choice(Q)
        pass_list[0] = random.choice(Q) ##pecial)
        pass_list[6] = random.choice(Q) 
        #if random.randint(0,1):
            
       #pass_list[6] = random.choice(Q)
        
    elif len(pass_list) == 8:# U1L1S1L1D1L3, L3U1L1S1L1D1, U1S1L1D1L4
        pass_list[1] = random.choice(Q)
        pass_list[3] = random.choice(Q)
        pass_list[5] = random.choice(Q)
        #if random.randint(0,1):
            #pass_list[7] = random.choice(Q)
            
    elif len(pass_list) > 8: # U6S1L3D4
        pass_list[len(pass_list)-2] = random.choice(Q)
        pass_list[1] = random.choice(Q)
        pass_list[random.randint(3, len(pass_list)-1)] = random.choice(Q)
        #pass_list[random.randint(0, len(pass_list)-1)] = random.choice(Special)
    #print(''.join(pass_list))
    #exit(1)
    return ''.join(pass_list)


if __name__ == "__main__":
    if len(sys.argv) != 2:    # Check if command-line arguments are provided 
        print("Usage: python3 strengthen.py <input_file_path>")
        sys.exit(1)
    process(sys.argv[1])

    #print(sys.argv[1])

'''
cd ..
python3 Test.py /home/csmajs/drios027/rockyou.txt.6.1.a
cd /home/csmajs/drios027/password_cs165
./pcfgc 1 rockyou.txt.6.1.a.strength  rockyou.txt.6.4.a.pcfg1 > crack-file
./pwdstats < crack-file
'''

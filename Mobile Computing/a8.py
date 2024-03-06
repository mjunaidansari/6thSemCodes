# A8 Authentication Algorithm 
import random

key=random.getrandbits(128)
ran=random.getrandbits(128)

keyb=bin(key)[2:]
ranb=bin(ran) [2:]

keybl=keyb[0:64]
keybr=keyb[64:]

ranbl=ranb[0:64]
ranbr=ranb[64:]

al=int(keybl,2)^int(ranbr,2)
a2=int(keybr,2)^int(ranbl,2)
a3=al^a2
a4=bin(a3)[2:].zfill(64)

print("128 Bit Key = ",keyb)
print("128 Random Bits Generated = ",ranb)
print("Ki = ",a4)
print("length of Ki= ",len(a4))
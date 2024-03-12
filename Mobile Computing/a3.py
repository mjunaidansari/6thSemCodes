# A3 Authentication Algorithm 
import random

k=random.getrandbits(128)
m=random.getrandbits(128)

kb=bin(k)[2:]
mb=bin(m)[2:]

kbl=kb[0:64]
kbr=kb[64:]

mbl=mb[0:64]
mbr=mb[64:]

al=int(kbl,2)^int(mbr,2)
a2=int(kbr,2)^int(mbl,2)
a3=al^a2
a4=bin(a3)[2:].zfill(64)
a5=a4[0:32]
a6=a4[32:]
a7=int(a5,2)^int(a6,2)

print("\n128 Bit Key = ",kb, "\n")
print("128 Random Bits Generated = ",mb, "\n")
print("RES/SRES = ",bin(a7)[2:].zfill(len(a5)), "\n")
encrypt = [ 0x25,0x3e,0x31,0x51,0x26,0x36,0x3a,0x2e,0x55,0x1c ]
outp = "i^vbopbsbk"
inp = "layerseven"
Flag = ""

for i in range(len(encrypt)):
    tmp = encrypt[i] ^ ord(outp[i]) ^ ord(outp[i])
    Flag += chr(tmp ^ ord(inp[i]))
print Flag

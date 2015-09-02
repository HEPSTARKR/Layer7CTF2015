import struct

fp = open("ReverseMe.mp3","rb")
fp2 = open("ReverseMe.exe","wb")
binary = []

while 1:
    f = fp.read(1)
    if f == '':
        break
    binary.append(ord(f))
fp.close()
binary.reverse()
for i in range(len(binary)):
    data = struct.pack('B',binary[i])
    fp2.write(data)
fp2.close()
print "Success!"

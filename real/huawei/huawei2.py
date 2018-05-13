lin = input()
n = int(input())
byes_lin = lin.encode('GBK')
byes_filter = 'qwertyuiopasdfghjklzxcvbnm1234567890QRTYUIOPASDFGHJKZXCVBNM'.encode('GBK')
byes_len = len(byes_lin)
cutted = byes_lin[:n]
chn_byte = 0
char_byte = 0
for c in cutted:
    if c in byes_filter:
        char_byte += 1
chn_byte = len(cutted) - char_byte
if chn_byte % 2 ==1:
    cutted = byes_lin[:n+1].decode('GBK')
else:
    cutted = byes_lin[:n].decode('GBK')

new_line_list = list(filter(lambda x: not '0'<=x<='9',cutted))
new_line = ''
for c in new_line_list:
    new_line+=c
print(new_line)
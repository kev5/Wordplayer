# Copyright 2017 Keval Khara kevalk@bu.edu
# Copyright 2017 Harish N Sathishchandra harishns@bu.edu
# Copyright 2017 Donato Kava dkava@bu.edu

import sys
import itertools


def check_word(words, checks):
    for i in words:
        if i not in checks:
            return False
        temp = checks.replace(i, '', 1)
        if len(temp) != len(checks) - 1:
            return False
        checks = temp
    return True


word_dic = {}
word_dic2 = {}
with open(sys.argv[1], 'r') as file:
    for line in file:
        line = line.rstrip()
        len_line = len(line)
        line1 = tuple(sorted(line))
        line2 = list(line)
        try:
            word_dic2[line1].add(line)
        except KeyError:

            word_dic2[line1] = set()
            word_dic2[line1].add(line)
        try:
            word_dic[len_line].append(line2)
        except KeyError:
            word_dic[len_line] = []
            word_dic[len_line].append(line2)
while(True):
    k = []
    oo = []
    m = []
    b = input()
    a = b.split()
    checks = a[0]
    if int(a[-1]) != 0 and int(a[-1]) <= len(checks):
        numOletters = int(a[-1])
        wordlen = len(checks)
        try:
            if wordlen - numOletters > 5:
                for words in word_dic[numOletters]:
                    if check_word(words, checks):
                        k.append(words)
            else:
                n = tuple(checks)
                n = sorted(n)
                for i in itertools.combinations(n, numOletters):
                    if i in word_dic2:
                        oo.append(word_dic2[i])
                    else:
                        pass
                if len(oo) != 0:
                    print(*sorted(set(
                          itertools.chain.from_iterable(oo))),
                          sep='\n')
        except KeyError:
            pass
        for i in k:
            m.append(''.join(i))
        z = sorted(m)
        for i in z:
            print(i)

        print('.')
    elif int(a[-1]) > len(checks):
        print('.')
    elif int(a[-1]) == 0:
        sys.exit(0)

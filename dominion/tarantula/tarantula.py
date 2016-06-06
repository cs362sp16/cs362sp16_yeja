import sys
import random
import os
import subprocess
import string

SYMBOLS = '====######====:'
FILES = ["dominion.c.gcov"]
numTests = 2000

def main():

    maxtests = 4

    unittests = ['unittest' + str(i) for i in range(1, maxtests + 1)]
    cardtests = ['cardtest' + str(i) for i in range(1, maxtests + 1)]
    testsuite = unittests + cardtests

    source = 'dominion.c'

    count = count_lines(source)
    passed = [0 for i in range(count + 1)]
    failed = [0 for i in range(count + 1)]
    totalp= 0
    totalf= 0

    for test in testsuite:

        subprocess.call(['make', 'clean'])
        subprocess.call(['make', test])
        try:
            temp = subprocess.check_output(['./' + test], stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            temp = e.output
        # record test result
        result = get_result(temp)
        if (result):
            # test passed
            totalp += 1
        else:
            # test failed
            totalf += 1
        # execute gcov on source file and record results
        subprocess.call(['gcov', source])
        for line in open(source + '.gcov', 'r').readlines():
            temp = line.split(':')
            num = temp[0].lstrip()
            i = int(temp[1])
            if num.startswith('-') or num.startswith('#') or num.startswith('='):
                continue
            elif result:
                # line executed by passing test
                passed[i] += 1
            else:
                # line executed by failing test
                failed[i] += 1
    # print tarantula results
    width = count_digits(count)
    i = 1
    for line in open(source, 'r').readlines():
        msg = str(i).rjust(width) + ':' + line[:-1]
        if passed[i] > 0 or failed[i] > 0:
            # some test executed this line
            temp = suspiciousness(passed[i], failed[i], totalp, totalf)
            if temp == 0:
                #passing lines
                printc_green(msg)
            elif temp <= 0.5:
                # somewhat passing lines
                printc_yellow(msg)
            else:
                # not passing
                printc_red(msg)
        else:
            print msg
        i += 1


def strange_coverage_unit(passed, failed, totalp, totalf):
    nume = failed / totalf
    denom = passed / totalp + nume

    return nume / denom

def build_test_dominion():
	print('Building testdominion')
	print(' Testing dominion Done.')

def get_result(file):

    return not msg.startswith('Checked')

def count_digits(n):
    count = 0
    while n != 0:
        count += 1
        n = n // 10
    return count

def printred(msg):
    '''
    TODO: write comment
    '''
    print '\033[91m' + msg + '\033[0m'

def printgreen(msg):
    '''
    TODO: write comment
    '''
    print '\033[92m' + msg + '\033[0m'

def printyellow(msg):
    '''
    TODO: write comment
    '''
    print '\033[93m' + msg + '\033[0m'

if __name__ == '__main__':
    main()


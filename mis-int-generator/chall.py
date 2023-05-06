
def f(x):
    if x == 0 or x == 2**36:
        return -x
    if x * x % (2**36) != 0:
        return -x
    else:
        return -x * (x - (2**36)) // (2**36)


def g(x):
    ret = x * 2 + x // 3 * 10 - x // 5 * 10 + x // 7 * 10
    ret = ret - ret % 2 + 1
    return ret, x // 100 % 100


def digit(x):
    cnt = 0
    while x > 0:
        cnt += 1
        x //= 10
    return cnt


def pad(x, cnt):
    minus = False
    if x < 0:
        minus = True
        x, cnt = g(-x)
    sub = 16 - digit(x)
    ret = x
    for i in range(sub - digit(cnt)):
        ret *= 10
        if minus:
            ret += pow(x % 10, x % 10 * i, 10)
        else:
            ret += pow(i % 10 - i % 2, i % 10 - i % 2 + 1, 10)
    ret += cnt * 10 ** (16 - digit(cnt))
    return ret


def int_generator(x):
    ret = -x
    x_ = f(x)
    cnt = 1
    while x_ > 0:
        ret = x_
        x_ = f(x_)
        cnt += 1
    return pad(ret, cnt)


X = 1008844668800884
for i in range(100000000):
    if int_generator(i) == X:
        print(i)
        break

X = 2264663430088446
for i in range(100000000):
    if i % 10000 == 0:
        print(i)
        
    if int_generator(i) == X:
        print(i)
        break

X = 6772814078400884
for i in range(1 << 35, 0, -1):
    if int_generator(i) == X:
        print(i)
        break


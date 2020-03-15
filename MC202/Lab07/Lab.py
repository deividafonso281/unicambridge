tempos_m = [3.279,3.2772,2.2928,1.8578,1.8808]
tempos_a = [3.3434,3.296,2.3976,1.862666667,1.8708]
tempos_d = [3.332,3.3588,2.3898,1.8868,1.8296]
tempos_i = [3.4012,3.3696,2.3466,1.9654,1.876]
y = [19.6,20.1,37.3,56.5,57.6]
for i in range(len(y)):
    y[i] = y[i]*(10**(-3))*50*(10**(-3))*9.7
    print(y[i])
for i in range(len(tempos_m)):
    tempos_m[i] = 1/(tempos_m[i]**2)
    print(tempos_m[i],end=" ")
print('')
for i in range(len(tempos_a)):
    tempos_a[i] = 1/(tempos_a[i]**2)
    print(tempos_a[i],end=" ")
print('')
for i in range(len(tempos_d)):
    tempos_d[i] = 1/(tempos_d[i]**2)
    print(tempos_d[i],end= " ")
print('')
for i in range(len(tempos_i)):
    tempos_i[i] = 1/(tempos_i[i]**2)
    print(tempos_m[i], end=" ")
print('')

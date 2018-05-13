N = int(input())

total_combination = pow(6,N)

#counter = [[0]*(6*N+1)]*(N+1)

counter = [[0 for i in range(6*N+1)] for i in range(N+1)]
def n_shaizi_k_sum(n:int, k:int):
    if k<n or k > 6 *n:
        return 0
    
    if n==1:
        counter[n][k]=1
        return 1
    else:
        
        if counter[n][k] == 0:
            counter[n][k] = \
            n_shaizi_k_sum(n-1,k-6)+\
            n_shaizi_k_sum(n-1,k-5)+\
            n_shaizi_k_sum(n-1,k-4)+\
            n_shaizi_k_sum(n-1,k-3)+\
            n_shaizi_k_sum(n-1,k-2)+\
            n_shaizi_k_sum(n-1,k-1)
        else:
            counter[0][0] += 1
        return counter[n][k]
result = []
for i in range(N, 6*N+1):
    result.append([i,round(n_shaizi_k_sum(N,i)/total_combination,5)])

print(result)
print(counter[0][0])
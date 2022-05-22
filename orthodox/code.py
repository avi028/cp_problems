def subarrayBitwiseOR(A): 
	res = set() 
	pre = {0} 
	for x in A: 
		pre = {x | y for y in pre} | {x} 
		res |= pre 
	return len(res) 

t = int(input())
for itr in range(t):
	n = int(input())
	a = []
	s = raw_input()
	for x in s.split():
		a.append(int(x))
	ans = subarrayBitwiseOR(a)
	ab = ((n*(n+1))/2)
	if ans == ab:
		print("YES\n")
	else :
		print("NO\n")
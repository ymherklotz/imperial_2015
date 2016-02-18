def fib(*arg):
	fib1 = [0, 1]
	if(len(arg) == 1):
		for x in range(2, arg[0]):
			fib1.append(fib1[x-2]+fib1[x-1])
		print(fib1)
	elif(len(arg) == 2):
		for x in range(2, arg[1]):
			fib1.append(fib1[x-2]+fib1[x-1])
		print(fib1[arg[0]-1:])

def main():
	fib(10, 20)

if __name__ == '__main__':
	main()
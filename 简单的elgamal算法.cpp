#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int GetYA(int a, int Xa, int q)//模幂运算
{
	int a = a;
	int tmp = 1;
	while (Xa)
	{
		if (Xa & 1)
			tmp = (tmp * a) % q;
		Xa >>= 1;
		a = (a * a) % q;
	}
	return tmp;
}

bool Isprime(int n)//判断是不是素数
{
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int Getgcd(int m, int n)
{
	int ret;
	while (ret = m % n)
	{
		m = n;
		n = ret;
	}
	return n;
}

int exGcd(int a, int b, int& x, int& y)//扩展的欧几里得算法 ※
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exGcd(b, a % b, x, y);
	int x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}
int main()
{
	int prime_q;
	int a;
	cin >> prime_q >> a;
	srand(time(nullptr));
	int Xa = rand() % prime_q;//产生随机整数XA
	cout << "私钥是：" << Xa << endl;
	int Ya = GetYA(a, Xa, prime_q);
	cout << "公钥是：(" << prime_q << "," << a << "," << Ya << ")" << endl;
	int m;//要计算的哈希值
	cout << "请输入m：";
	cin >> m;
	//srand(time(nullptr));
	int K = rand() % prime_q;
	while (Getgcd(K, prime_q - 1) != 1)
		K = rand() % prime_q;
	int S1 = GetYA(a, K, prime_q);
	int x = 0, y = 0;
	x = exGcd(K, prime_q - 1, x, y);
	int X = (x % (prime_q - 1) + (prime_q - 1)) % (prime_q - 1);
	int S2 = X * (m - (Xa * S1)) % (prime_q - 1);
	cout << "(S1,S2)=" << S1 << "," << S2 << endl;
	return 0;
}
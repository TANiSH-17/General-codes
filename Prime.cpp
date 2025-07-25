Method 1:- √n Method

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


Method 2:- Sieve of Eratosthenes (Precomputation)
int x = 4 * 1e6 + 1;
vector<bool> prime(x, true);
prime[0] = prime[1] = false;

for (int i = 2; i * i < x; ++i) {
    if (prime[i]) {
        for (int j = i * i; j < x; j += i)
            prime[j] = false;
    }
}


Suppose the array primes, defined as

double primes[] = { 2, 3, 5, 7, 11, 13 };
starts at memory location 20300. What are the values of

a. primes
        output: 20300
            (Start memory location of array)

b. *primes
        output: 2
            (Value at start memory location of array)

c. primes + 4
        output: 20332
            (memory location of 4th index element in array;
                20300 + 4 * sizeof(double)
                = 20300 + 4 * 8
                = 20300 + 32
                = 20332)

d. *(primes + 4)
        output: 11
            (Value at 4th index in array )

e. primes[4]
        output: 11
            (same as * (primes + 4)
                Value at 4th index in array)

f. &primes[4]
        output: 20332
            (same as (primes + 4)
                Memory location of 4th index element in array
                    20300 + 4 * sizeof(double)
                    = 20300 + 4 * 8
                    = 20300 + 32
                    = 20332))

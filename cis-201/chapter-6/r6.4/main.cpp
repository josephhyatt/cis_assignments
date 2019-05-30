Consider the following array:

int a[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0 };
What are the contents of the array a after the following loops complete?

a.for (int i = 1; i < 10; i++) { a[i] = a[i - 1]; }
    Output: 1 1 1 1 1 1 1 1 1 1

b.for (int i = 9; i > 0; i--) { a[i] = a[i - 1]; }
    Output: 1 1 2 3 4 5 4 3 2 1

c.for (int i = 0; i < 9; i++) { a[i] = a[i + 1]; }
    Output: 2 3 4 5 4 3 2 1 0 0

d.for (int i = 8; i >= 0; i--) { a[i] = a[i + 1]; }
    Output: 0 0 0 0 0 0 0 0 0 0

e.for (int i = 1; i < 10; i++) { a[i] = a[i] + a[i - 1]; }
    Output: 1 3 6 10 15 19 22 24 25 25

f.for (int i = 1; i < 10; i = i + 2) { a[i] = 0; }
    Output: 1 0 3 0 5 0 3 0 1 0

g.for (int i = 0; i < 5; i++) { a[i + 5] = a[i]; }
    Output: 1 2 3 4 5 1 2 3 4 5

h.for (int i = 1; i < 5; i++) { a[i] = a[9 - i]; }
    Output: 1 1 2 3 4 4 3 2 1 0




1.
(define (filter-range lst a b)
    (if (null? lst) '()
        (if (and (<= a (car lst)) (>= b (car lst))) (cons (car lst) (filter-range (cdr lst) a b))
            (filter-range (cdr lst) a b)
        )
    )
)

2.
(define (k-th-element lst k)
    (if (null? lst) "None"
        (if (zero? k) (car lst) 
            (k-th-element (cdr lst) (- k 1))
        )
    )
)

3.
(define (helper n k)
    (if (equal? k 1) #t
        (if (zero? (remainder n k)) #f
            (helper n (- k 1))
        )    
    )
)

(define (prime? n)
    (if (equal? n 1) #f
        (helper n (- n 1))
    )
)

4.
(define (primes? lst)
    (if (null? lst) '()
        (if (prime? (car lst)) (cons #t (primes? (cdr lst)))
            (cons #f (primes? (cdr lst)))
        )
    )
)

(define (primes? lst)
    (if (null? lst) '()
        (cons (prime? (car lst)) (primes? (cdr lst)))
    )
)

(define (primes? lst)
    (map prime? lst)
)

5.1
(define (helper k n)
    (if (zero? k) '()
        (cons (- n k) (helper (- k 1) n))
    )
)

(define (generate-list k)
    (helper k (+ k 1))
)

5.2 
(define (power n)
    (if (zero? n) 1
        (* 2 (power (- n 1)))
    )
)

5.3
(define (generate-power-list k)
    (map power (generate-list k))
)

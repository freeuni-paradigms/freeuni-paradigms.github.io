1. 
(define (first-elem lst)
    (if (null? lst) "None"
    (car lst))
)

2. 
(define (abs n)
    (if (negative? n) (- 0 n) n)
)

3. 
(define (right-triangle? lst)
    (if (equal? (+ (expt (car lst) 2) (expt (cadr lst) 2)) (expt (caddr lst) 2)) #t 
    #f)
)

(define (right-triangle? lst)
    (equal? (+ (expt (car lst) 2) (expt (cadr lst) 2)) (expt (caddr lst) 2))
)

4.
(define (last-elem lst)
    (if (null? lst) "None"
        (if (null? (cdr lst)) (car lst)
            (last-elem (cdr lst)))
    )
)

5.
(define (length lst)
    (if (null? lst) 0
        (+ 1 (length (cdr lst))))
)

6.
(define (filter-range lst a b)
    (if (null? lst) '()
        (if (and (<= a (car lst)) (>= b (car lst))) (cons (car lst) (filter-range (cdr lst) a b))
            (filter-range (cdr lst) a b)
        )
    )
)


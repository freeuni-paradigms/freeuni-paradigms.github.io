1.
(define (digits n)
    (if (zero? n) '()
        (cons (remainder n 10) (digits (quotient n 10)))
    )
)

(define (length lst)
    (if (null? lst) 0
        (+ 1 (length (cdr lst)))
    )
)

(define (narcisisstic? n)
    (equal? (apply + (map (lambda (digit) (expt digit (length(digits n)))) (digits n))) n)
)


2.
(define (is-equal first second)
    (if (equal? first second) 1
        0
    )
)

(define (frequency lst digit)
    (apply + (map (lambda (elem) (is-equal elem digit)) lst))
)

(define (frequency-list lst)
    (map (lambda (digit) (frequency lst digit)) (list 0 1 2 3 4 5 6 7 8 9))
)

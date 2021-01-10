(define (is-palindrome? l)
  (if (equal? (reverse l) l) #t
      #f))

;Removes last element from the list.
(define (remove-last-element l)
	(reverse (cdr (reverse l))))

;Returns the largest palindrome, which starts with the first element of the current list.
(define (get-palindrome l)
  (cond ((null? l) '())
	((is-palindrome? l) l)
	((get-palindrome (remove-last-element l)))))

(define (find-result l l2)
  (cond ((null? l) l2)
        ((> (length l2) (length l)) l2)
	((<= (length l2) (length (get-palindrome l))) (find-result (cdr l) (get-palindrome l)))
	((find-result (cdr l) l2))))

(define (largest-palindrome l)
  (find-result l '()))

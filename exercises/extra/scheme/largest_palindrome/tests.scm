(load "largest_palindrome.scm")
	
;; TEST ALL
(display (equal? '(1 1 1 1) (largest-palindrome '(1 1 1 1))))(newline)
(display (equal? '(1) (largest-palindrome '(1))))(newline)
(display (equal? '() (largest-palindrome '())))(newline)
(display (equal? '(1 1 1 1 1) (largest-palindrome '(1 1 1 1 1 2))))(newline)
(display (equal? '(1 0 1 2 1 0 1) (largest-palindrome '(5 1 0 1 2 1 0 1 2 3))))(newline)
(display (equal? '(2 2 1 2 2) (largest-palindrome '(1 2 2 1 2 2))))(newline)
(display (equal? '(6) (largest-palindrome '(1 2 3 4 5 6))))(newline)
(display (equal? '(1 2 2 2 2 2 2 2 2 2 2 1) (largest-palindrome '(1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 1))))(newline)


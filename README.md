Blaga Ana-Maria-Andreea, 334CB

Varianta neopt:
    Am observat ca anumite inmultiri intre A si At nu sunt relevante (dau 0 
    deoarece matricea A este superior triunghiulara). Am facut un exemplu pe 
    foaie si am observat ca doar atunci cand k >= i && k >= j se obtin 
    elemente nenule in cadrul inmultirii A[i * N + k] * At[k * N + j].

    Am inmultit matricea rezultata cu matricea B. Am inmultit matricea Bt cu 
    matricea B si am adaugat rezultatul la matricea obtinuta anterior.

    Inmultirea a doua matrice este facuta basic, pe baza algoritmului 
    matematic (fiecare linie cu fiecare coloeana).

    Transpunerea unei matrice este facuta basic, pe baza algoritmului 
    matematic (se interschimba A[i][j] cu A[j][i]).

Varianta opt_m:
    Transpunerea din algoritmul neoptimizat am optimizat-o inlocuid accesele
    vectoriale prin derefentiere utilizand pointeri (asa cum era sugerat in 
    laboratorul 5) si loop unrolling deoarece se precizeaza in enunt ca N 
    este multiplu de 40.

    Inmultirea dintre A si At am optimizat-o folosind pointeri si am luat 
    in considerare faptul ca nu am nevoie de matricea A transpusa pentru 
    a face inmultirea si ma pot folosi tot de A realizand astfel inmultiri 
    linie-linie.

    Inmultirile si adunarea dintre doua matrice am optimizat-o folosind 
    loop unrolling si utilizand pointeri.

    Inmultirea lui Bt cu B am optimizat-o asemenea inmultirii A*At, insa 
    aici am folosit matricea Bt pentru a realiza inmultirile linie-linie.

Varianta blas:
    Pentru inmultirea dintre A si At am folosit cblas_dtrmm (functie 
    speciala pentru inmultirea unei matrice triunghiulare).

    Pentru inmultirea lui B cu A si At am folosit cblas_dgemm, iar in 
    final folosesc tot cblas_dgemm pentru a inmulti Bt cu B si a-l adauga 
    la rezultat.

Cachegrind:
    Observam ca I refs (counting instruction reads) este cel mai mare la 
    varianta neoptimizata, apoi optimizata si in final cel mai mic la cea blas.
    
    I1 misses (1st level instruction cache misses) este aproximativ la fel la 
    varianta optimizata si la cea neoptimizata, dar mult mai mare la cea blas.
    Analog LLi misses (last level cache instruction misses).

    D refs (data reads) este cel mai mare la varianta neoptimizata, apoi 
    optimizata si in final cel mai mic la cea blas. Analog D1 misses 
    (1st level data cache misses). 

    Lld misses (last level cache data misses) este cel mai mic la varianta 
    neoptimizata, apoi optimizata si in final cel mai mare la cea blas.

    Varianta neoptimizata si cea optimizata au aproximativ acelasi numar de 
    branches mispredicted (conditional and indirect branches), iar varianta 
    blas unul mult mai mic.

    Observam ca branches este cel mai mare la varianta neoptimizata, apoi 
    optimizata si in final cel mai mic la cea blas.

    Varianta blas are cel mai mare Mispred rate, urmata de cea optimizata, 
    apoi de cea neoptimizata. 

Analiza comparativa a performantei pentru cele 3 variante:
    Varianta neoptimizata obtine cele mai slabe rezultate din punct de vedere 
    al vitezei deoarece tine cont doar de faptul ca matricea A e superior 
    triunghiulara si nu beneficiaza de niciun fel de optimizare.

    Varianta optimizata obtine performante mai bune decat varianta 
    neoptimizata deoarece am folosit loop unrolling, pointeri si registre 
    acolo unde s-a putut.

    Varianta blas este cea mai rapida deoarece biblioteca blas contine un set 
    de rutine de nivel scazut. BLAS profita de hardware special in virgula 
    mobila, cum ar fi registrele vectoriale sau instructiunile SIMD.

Input pentru grafic:
5
400 123 out1
600 643 out2
800 456 out3
1000 632 out4
1200 789 out5

Neoptimizat:
Run=./tema2_neopt: N=400: Time=1.006896
Run=./tema2_neopt: N=600: Time=3.368408
Run=./tema2_neopt: N=800: Time=9.388363
Run=./tema2_neopt: N=1000: Time=18.870987
Run=./tema2_neopt: N=1200: Time=34.239143

Optimizata:
Run=./tema2_opt_m: N=400: Time=0.244059
Run=./tema2_opt_m: N=600: Time=0.820511
Run=./tema2_opt_m: N=800: Time=1.930838
Run=./tema2_opt_m: N=1000: Time=3.915608
Run=./tema2_opt_m: N=1200: Time=6.947524
<<< Bonus=5p >>>

Blas:
Run=./tema2_blas: N=400: Time=0.047192
Run=./tema2_blas: N=600: Time=0.155157
Run=./tema2_blas: N=800: Time=0.343883
Run=./tema2_blas: N=1000: Time=0.678905
Run=./tema2_blas: N=1200: Time=1.136290

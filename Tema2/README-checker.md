<!--Copyright PCLP Team, 2025-->

# Checker PCLP pentru temele de casă

Acesta este README-ul pentru checker-ul de la teme la materia PCLP. Vă rugăm să descărcați arhiva cu checker-ul local la fiecare temă și la fiecare actualizare a acestuia.

- [Checker PCLP pentru temele de casă](#checker-pclp-pentru-temele-de-casă)
	- [Instalare](#instalare)
	- [Utilizare](#utilizare)
	- [Makefile](#makefile)
		- [Crearea fișierului Makefile](#crearea-fișierului-makefile)
	- [README](#readme)
	- [Erori uzuale](#erori-uzuale)
	- [Ierarhie teste](#ierarhie-teste)

## Instalare

* Bash (versiunea default de pe OS) și Python 3 (>= 3.6) deja instalate pe sistem. Pe Ubuntu 24 ar trebui să aveți deja această parte configurată:

```shell
$ python3 --version
Python 3.12.3

$ bash --version
GNU bash, version 5.2.21(1)-release (aarch64-unknown-linux-gnu)
```

* Un exemplu de instalare pe Ubuntu:

```shell
$ sudo ./install
```

Dacă scriptul eșuează, încercați să instalați manual dependențele prezente în acesta (gcc, make, pachete de Python).

## Utilizare

În funcție de cum aveți sistemul configurat, puteți rula checker-ul pentru a vedea pagina de help, în unul din
următorele 2 moduri.

```shell
# Varianta 1 de rulare:
$ ./check --help
# Varianta 2 de rulare:
$ python3 ./check --help

usage: check [-h] [--task {battleships}] [--legend {True,False}]

check homework

optional arguments:
  -h, --help            show this help message and exit
  --task {battleships}
                        task name
  --legend {True,False}
                        print legend
```

Ca să rulăm checker-ul doar pentru o problemă pasăm `--task $nume_problemă`. De exemplu, următoarea comandă va
rula checker-ul pentru problema `battleships`:

```shell
$ python3 ./check --task battleships
+++++ check_deps ...
system               - Linux
	 config: Darwin MacBook-Pro.local 23.6.0 Darwin Kernel Version 23.6.0: Fri Jul  5 17:53:24 PDT 2024; root:xnu-10063.141.1~2/RELEASE_ARM64_T6020 arm64
gcc                  - installed
	version: Apple clang version 15.0.0 (clang-1500.1.0.2.5)
make                 - installed
	version: GNU Make 3.81
python3              - installed
	version: Python 3.9.6
----- check_deps

+++++ make_build ...
----- make_build
+++++ running all tasks

+++++ running all tasks

	+++++ running task battleships (80p) ...

		+++++ running test 00-battleships
			running test       - OK
				stage time: 0:00:00.459439
			running check      - OK
				stage time: 0:00:00.059390
		----- running test 00-battleships - grade 8/8

		+++++ running test 01-battleships
			running test       - OK
				stage time: 0:00:00.005056
			running check      - OK
				stage time: 0:00:00.044647
		----- running test 01-battleships - grade 8/8

		+++++ running test 02-battleships
			running test       - OK
				stage time: 0:00:00.005140
			running check      - OK
				stage time: 0:00:00.039993
		----- running test 02-battleships - grade 8/8

		+++++ running test 03-battleships
			running test       - OK
				stage time: 0:00:00.005098
			running check      - OK
				stage time: 0:00:00.040885
		----- running test 03-battleships - grade 8/8

		+++++ running test 04-battleships
			running test       - OK
				stage time: 0:00:00.005221
			running check      - OK
				stage time: 0:00:00.037343
		----- running test 04-battleships - grade 8/8

		+++++ running test 05-battleships
			running test       - OK
				stage time: 0:00:00.005116
			running check      - OK
				stage time: 0:00:00.038376
		----- running test 05-battleships - grade 8/8

		+++++ running test 06-battleships
			running test       - OK
				stage time: 0:00:00.005348
			running check      - OK
				stage time: 0:00:00.037244
		----- running test 06-battleships - grade 8/8

		+++++ running test 07-battleships
			running test       - OK
				stage time: 0:00:00.005175
			running check      - OK
				stage time: 0:00:00.035926
		----- running test 07-battleships - grade 8/8

		+++++ running test 08-battleships
			running test       - OK
				stage time: 0:00:00.005103
			running check      - OK
				stage time: 0:00:00.036047
		----- running test 08-battleships - grade 8/8

		+++++ running test 09-battleships
			running test       - OK
				stage time: 0:00:00.005169
			running check      - OK
				stage time: 0:00:00.035196
		----- running test 09-battleships - grade 8/8

	----- running task battleships - grade 80/80

----- running all tasks

+++++ running check_style (10p)...
No coding style errors automatically detected. Final points are given after manual grading.
----- running check_style - grade 10/10

+++++ running check_readme (10p) ...
Found non-empty'README'!
----- running check_readme - NO grade given yet, final points are given after manual grading.

+++++ make_clean ...
----- make_clean
Total: 90/90 (README is not checked)


Total execution time: 0:00:02.320929
```

Dacă rulăm checker-ul fără parameterul `--task`, acesta va evalua toate problemele / toată tema.

## Makefile

Checker-ul testează pas cu pas, tema curentă. De exemplu, trebuie să aveți un fișier `Makefile` și sursele trebuie să aibă numele specificat în enunț.

### Crearea fișierului Makefile

* În directorul de teme aveti 3 template-uri pentru Makefile-uri. Alegeți oricare template si redenumiți fișierul în `Makefile`.
* Fiecare din template-uri are mai multe reguli de creare(make). Cele mai uzuale sunt:
	- **build**: Compilează și generează executabilul/executabilele necesare.
	- **pack**: Generează arhiva cu toate fișierele necesare trimiterii temei (fișiere .c și .h, Makefile și README).
	- **clean**: Șterge toate fișierele generate la build (executabile, binare intermediare etc).

* Un exemplu pentru `make pack` ar arăta astfel:
```bash
$ make pack
zip -FS "PCLP3XYCA_FirstnameLastname_Tema2.zip" *.c *.h Makefile README
  adding: battleships.c (deflated 40%)
  adding: Makefile (deflated 36%)
  adding: README (deflated 76%)
```

* Astfel, aveți generată arhiva și o puteți trimite pe Moodle.

* Dacă fișierul Makefile lipsește, checker-ul vă atenționează cu eroarea `Makefile is missing!`:

```shell
...

+++++ make_build ...
Makefile is missing!

			Final grade: 0
TOTAL: 0/90


Total execution time: 0:00:00.061070
```


## README

* Pentru structura unui README urmați indicațiile de pe ocw la secțiunea [regulament-teme](https://ocw.cs.pub.ro/courses/programare/regulament#temele_de_casa1).
* **Tip**: Pentru a vizualiza în VSCode cum arată fișierul README in markdown puteți da click dreapta pe fișierul README în bara de open editors, apoi "Open preview" sau apăsați combinația de taste Ctrl + Shift + V (⌘ + Shift + V pe Mac).

## Erori uzuale

* Citiți cu atenție cerințele din enunțuri și regulamentul temei curente. De exemplu, numele fișierelor Makefile, README, surselor, executabilelor etc.
* Citiți cu atenție outputul de la checker, linie cu linie. Dacă acesta doreste să instalați ceva, va print un mesaj.

Erori la `build`: În această etapă se încearcă compilarea codului.
	2.1. Fișierul `Makefile`: Trebuie să fie prezent.
	2.2. Comanda `make`:  `make build` trebuie să compileze fișierele ca în enunț.
	2.3. `warnings`:  Se aplică depunctări automate, ca în enunț.

Erori la `run`: În această etapă se încearcă rularea executabilelor.
	3.1 `run`: Se rulează executabilul pe un singur test.
	3.2 `check`: Dacă `run` a fost cu success (programul a ieșit cu cod 0), se verifică outputul produs.
	3.3 `valgrind`: La temele cu alocare dinamică, se verifică încă o dată pentru memory leaks. Se poate suprascrie punctajul de la etapa `check`.

	Legendă cu erori semnalate de checker:
	1. `UPS`: Ups, programul a crăpat!
        Programul a ieșit cu cod diferit de 0! Checker-ul nu poate detecta în mod automat eroarea, dar vă recomandăm să rulați manual testul respectiv. Exemple posibile: recursivitate infinită, acces invalid la memorie, dereferențiere de pointeri invalizi etc.
	2. `TLE`: Time Limit Exceed (timp de executie depășit)
		De obicei, acest lucru înseamnă ciclu infinit, deoarece la PCLP nu avem constrângeri de performanță. Cu toate acestea, la unele probleme se pot cere explicit în enunț soluții mai eficiente.
	3. `MLE`: Memory Limit Exceed (limită de memorie depășită)
		De obicei, acest lucru înseamnă că ați alocat prea multe tablouri sau aveți prea multe apeluri recursive, deoarece la PCLP nu avem constrângeri de memorie exacte. Cu toate acestea, la unele probleme se pot cere explicit în enunț soluții mai eficiente.
	4. `MEM_UPS`: Memory leaks or errors
		După rularea cu valgrind, checker-ul a găsit memory leaks, accesse invalide la memorie, eliberări duble de memorie, utilizări de zone de memorie după ce acestea au fost eliberate etc. Vă recomandăm să rulați manual testul respectiv cu valgrind.
	5. `WA`: Wrong Answer (wrong or partial output)
		Programul s-a terminat cu success (cod 0), dar nu a produs outputul cerut (total sau parțial.)
	6. `OK`: Viața e frumoasă
        Pe un test marcat OK, programul se termină cu succes (cod 0),
        nu are erori de timp sau memorie detectate în mod automat, iar outputul produs este identic cu cel cerut pentru respectivul test.

Erori de `style`: Se va rula automat un checker de coding style, care va raporta toate erorile pe care le aveți, conform https://ocw.cs.pub.ro/courses/programare/coding-style. Acesta va acorda puncte bonus (proporțional cu punctajul pe teste) sau penalizări.


Erori la `README`: Checker-ul NU poate verifica calitatea fișierului README, însă vă ajută să nu uitați să adaugați totuși un README în rezolvare.

Erori la `clean`: `make clean` ar trebui să curețe fișierele produse la build.

`grade`: Reprezintă nota/punctajul pe care îl primiți pe o anumită categorie.

## Ierarhie teste

Pentru folosirea manuală a testelor, test cu test, puteți să accesați testele cu fișierele de intrare (`*.in`) și cele de referință (`*.ref` - care conțin răspunsurile corecte), din folderul `tasks/`.

De exemplu, pentru problema `battleships`, testele se găsesc în `tasks/battleships/tests `:

```shell
$ ls -l tasks/battleships/tests
total 0
drwxr-xr-x  7 dariusn  staff  224 Oct 31 08:12 00-battleships
drwxr-xr-x  5 dariusn  staff  160 Oct 31 08:12 01-battleships
...
```

Dacă dorim să inspectăm ce output / eroare a produs programul nostru la problema `battleships`, pe testul `00`, putem să ne uităm la următoarele fișiere:

```shell
$ ls -l tasks/battleships/tests/00-battleships
total 40
-rw-r--r--  1 dariusn  staff   63 Oct 31 08:12 00-battleships.in    # Datele de intrare (STDIN) pentru testul 00.
-rw-r--r--  1 dariusn  staff  243 Oct 30 22:34 00-battleships.ref   # Datele de ieșire corecte pentru testul 00.
-rw-r--r--  1 dariusn  staff  243 Oct 31 07:48 00-battleships.out   # Datele de ieșire (STDOUT) produse de programul nostru pentru testul 00 (sau chiar un fișier, în funcție de temă).
-rw-r--r--  1 dariusn  staff   12 Oct 31 07:48 00-battleships.error # Datele de eroare (STDERR) produse de programul nostru pentru testul 00.
```

Dacă dorim să folosim un fișier de test pentru o rulare manuală înafara checker-ului, putem folosi redirectări:

```shell
# Compilare manuală.
$ make

# Rulare manuală test 00: citire input cu redirectare din fișier, afișare la STDOUT a rezultatului.
$ ./battleships < tasks/battleships/tests/00-battleships/00-battleships.in

# Rulare manuală test 00: citire input cu redirectare din fișier, afișare cu redirectare output în fișierul hai_steaua.out
$ ./battleships < tasks/battleships/tests/00-battleships/00-battleships.in > hai_steaua.out
```

În cazul în care aveți nevoie de ajutor cu debugging (de exemplu, programul are un crash sau memory leaks), puteți să consultați tutorialele de pe OCW:

- [Debugging](https://ocw.cs.pub.ro/courses/programare/debugging)
- [Logging](https://ocw.cs.pub.ro/courses/programare/logging)
- [Good Practices](https://ocw.cs.pub.ro/courses/programare/tutoriale/good_practices)
- [Coding style PCLP laborator și teme](https://ocw.cs.pub.ro/courses/programare/coding-style)

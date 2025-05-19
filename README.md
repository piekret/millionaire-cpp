# Millionaire – quiz terminalowy

## Kompilacja

```bash
# GCC / Clang
mkdir build && cd build
g++ -std=c++17 -O2 ../src/*.cpp -o millionaire

# MSVC
cl /std:c++17 /O2 /EHsc ..\src\*.cpp /Fe:millionaire.exe
```

## ALBO

```bash
Odpalasz w VS / VS Code i klikasz Build
```

Wymagany jest kompilator zgodny z C++17.

---

## Uruchamianie

```bash
./millionaire [opcje]
```

| Opcja               | Działanie                                 |
| ------------------- | ----------------------------------------- |
| `-help`             | Wyświetla pomoc                           |
| `-questions=<plik>` | Ładuje pytania z pliku CSV                |
| `-nick=<nazwa>`     | Ustawia nazwę gracza (domyślnie `player`) |
| `-last`             | Kontynuuje ostatnią niedokończoną grę     |

Przykład:

```bash
./millionaire -questions=historia.csv -nick=Asia
```

---

## Sterowanie

| Klawisz | Funkcja                                       |
| ------- | --------------------------------------------- |
| `A–D`   | Wybór odpowiedzi                              |
| `H`     | Koło 50/50                                    |
| `U`     | Pytanie do publiczności                       |
| `P`     | Telefon do przyjaciela                        |
| `Q`     | Zakończenie gry z wypłatą gwarantowanej kwoty |

---

## Format pliku pytań (CSV)

```
"Pytanie";"Odp A";"Odp B";"Odp C";"Odp D";<poprawna litera>
```


Plik powinien być zapisany w kodowaniu UTF‑8.



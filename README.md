# 💰 Millionaire – gra terminalowa

Prosty quiz w stylu *Milionerów*: 15 pytań, trzy koła ratunkowe, tablica rekordów.

---

## ⚙️ Kompilacja

```bash
# GCC / Clang
mkdir build && cd build
g++ -std=c++17 -O2 ../src/*.cpp -o millionaire

# MSVC (w wierszu polecenia "Developer")
cl /std:c++17 /O2 /EHsc ..\src\*.cpp /Fe:millionaire.exe
```

# ALBO
```bash
Odpalasz projekt w VS / VS Code i klikasz Build
```

Wymagany jest kompilator C++17 lub nowszy (używamy `<filesystem>`).

---

## 🚀 Uruchamianie

```bash
./millionaire [opcje]
```

| Opcja               | Opis                                                            |
| ------------------- | --------------------------------------------------------------- |
| `-help`             | Pokaż pomoc i zakończ.                                          |
| `-questions=<plik>` | Wczytaj własny plik CSV z pytaniami.                            |
| `-nick=<nazwa>`     | Ustaw nick gracza (domyślnie `player`).                         |
| `-last`             | Kontynuuj ostatnio przerwaną rundę (z pliku `assets/last.csv`). |

Przykład:

```bash
./millionaire -questions=historia.csv -nick=Asia
```

---

## 🕹️ Sterowanie

| Klawisz | Działanie                             |
| ------- | ------------------------------------- |
| `A–D`   | Wybór odpowiedzi                      |
| `H`     | 50/50                                 |
| `U`     | Pytanie do publiczności               |
| `P`     | Telefon do przyjaciela                |
| `Q`     | Zakończ i wypłać gwarantowaną wygraną |

---

## 📄 Format pytań (CSV)

```
"Pytanie";"Odp A";"Odp B";"Odp C";"Odp D";<litera poprawnej>
```

Przykład:

```
"Stolica Polski?";"Warszawa";"Kraków";"Gdańsk";"Wrocław";A
```

Plik **musi** być zapisany w UTF‑8.

---

## 📂 Struktura katalogów

```
assets/
 ├─ default_questions.csv   # domyślne pytania
 ├─ scores.csv              # top‑10 wyników
 ├─ last.csv                # automatyczny zapis niedokończonej gry
 └─ logo.txt                # baner ASCII
```

---

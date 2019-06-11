# penkta_uzduotis

## Programos tikslas:
* Suskaičiuoti, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tuomet realizacijos output'e (išoriniame faile) išvesti skirtingus žodžius, kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
* Sukurti cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
* URL adresų suradimas tekste: išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)

## Programos ypatybės:
* prireikė nestandartinių include: #include <regex>, #include <map>
* funkcija ``std::transform(eilute.begin(), eilute.end(), eilute.begin(), tolower);`` leidžianti paversti didžiąsias raides į mažąsias
* ``word.erase(remove_if(word.begin(), word.end(), [](char s) {
                           return s == ',' || s == '-' || s == '.' || s == '!' || s == '?' || s == '(' || s == ')' ||
                                  s == '„' || s == '“'; }), word.end()); `` padedanti pašalinti nereikalingus skyrybos ženklus
*  ``if (std::regex_match(w, std::regex(
                        "[(http(s)?):\\/\\/(www\\.)?a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)")))`` if'o sąlyga, leidžianti surasti url tekste
  
## Programos rezultatai
* išvedami į "rez.txt". Fragmentas:
```
'apsikeistume' is viso pasikartojo 2 kartus:
1 eiluteje(-ese) 2 karta(-us)

 'ar' is viso pasikartojo 8 kartus:
5 eiluteje(-ese) 2 karta(-us)
6 eiluteje(-ese) 1 karta(-us)
10 eiluteje(-ese) 2 karta(-us)
12 eiluteje(-ese) 2 karta(-us)
14 eiluteje(-ese) 1 karta(-us)

```
* url adresai:
```
'https://www.facebook.com/agnejagelaviciutestilius/posts/1262875540528237'  eiluteje : 17
'https://www.facebook.com/plepytee/'  eiluteje : 16
```
## Programos paleidimas
* tereikia pasileisti CMakeLists.txt
* arba komandinėje eilutėje įvykdyti komandas:
```
g++ -o programa main.cpp
./programa
cd cmake-build-debug
nano rez.txt
```

  

1. Dodatni zadatak (2025)
Realizovati sistem štoperice koja broji vreme u sekundama (maksimalna vrednost koja se može prikazati je 60 minuta - broji od 00:00 do 60:00) korišćenjem Arduino Mega 2560 i pomoćnih uređaja u Proteusu:
- Taster za aktivaciju/deaktvaciju brojanja
- Taster za resetovanja brojača na 00:00
- LCD displej LM-016L 
NAPOMENA: Zadatak se radi individualno i nosi do 15 poena. Veći broj poena dobijaju rešenja koja uspevaju da primene tajmer za merenje vremena i prekide. Realizaciju funkcionalnosti oba tastera realizovati obavezno uz pomoć zasebnih prekida. Pored kvaliteta rešenja, redosled predaje zadatka može uticati na broj poena (do 2 poena razlike po redosledu predaje rešenja).


2. Dodatni zadatak (2025)
Proučiti rad sa EEPROM memorijom kod Arduina: https://docs.arduino.cc/learn/programming/eeprom-guide/ 
Realizovati uz pomoć Arduino Mega sistem regulacije kvaliteta vazduha zatvorene prostorije koji uz pomoć DHT22 meri relativnu vlažnost i temperaturu vazduha, a ukoliko su vrednosti izvan opsega - otvara se prozor uz pomoć servo motora. U EEPROM memoriji se na adresama 0 i 1, redom, čuvaju granične (maksimalne) vrednosti vlažnosti i temperature. Ukoliko je bar jedna vrednost (vlažnost ili temperatura) viša od granične - prozor se otvara rotiranjem servo motora do kraja u jednom smeru. Kada se, nakon toga, vrednosti ponovo nađu ispod graničnih, prozor se zatvara rotiranjem servo motora u suprotnom smeru do početne pozicije. Osim toga, dodati taster za paljenje/gašenje sistema, koji ove funkcionalnosti realizuje preko prekida. Pri paljenju sistema se granične vrednosti čitaju iz EEPROM memorije i sistem svake 1.5s meri vrednosti sa DHT22. Po gašenju sistema, prestaje merenje i reakcija na promene parametara vazduha,

NAPOMENA: Zadatak se radi individualno i nosi do 15 poena. Veći broj poena dobijaju rešenja koja uspevaju da primene adekvatno tajmere i prekide. Pored kvaliteta rešenja, redosled predaje zadatka može uticati na broj poena (do 2 poena razlike po redosledu predaje rešenja).

3. Dodatni zadatak (2025)
Realizovati uz pomoć Arduino Mega sistem merenja temperature koji uzima u obzir srednju vrenost dva senzora - DHT22 i TMP36 i prikazuje na LCD displeju.  Za realizaciju koristiti FreeRTOS i taskove. Sistem ažurira temperaturu na LCD-u svakih 5 sekundi. Prvo meri sa DHT22. Nakon 2 sekunde meri vrednost sa senzora TMP36. Ukloiko je razlika izmerenih temperatura veća od 2 stepena - štampa se poruka "Neprecizno merenje", pali se crvena LED dioda (u suprotnom je ugašena). 

NAPOMENA: Zadatak se radi individualno i nosi do 15 poena. Obavezno koristiti FreeRTOS. Veći broj poena dobijaju rešenja koja uspevaju da primene adekvatno tajmere i prekide tamo gde ima smisla. Pored kvaliteta rešenja, redosled predaje zadatka može uticati na broj poena (do 2 poena razlike po redosledu predaje rešenja).

4. Dodatni zadatak (2025)
Proučiti potenciometre u Proteusu. Realizovati uz pomoć Arduino Mega sistem relejne žaštite koji uzima u obzir promenu napona u zadatom vremenskom intervalu. Za realizaciju koristiti FreeRTOS i taskove. Sistem ažurira pročitanu vrednost napona zadatu potenciometrom svakih 6 sekundi i ako je razlika veća od granične razlike - gasi proizvoljnog potrošača preko jednokanalnog releja. Kada razlika padne ispod granične, ponovo pali potrošača preko releja. Graniču vrednost razlike napona čuvati u EEPROM-u, a pritiskom na dugme aktivacije/deaktivacije (realizacija preko interrupt-a) se čita vrednost po aktivaciji.

Moguće varijante: a) Na početu ciklusa od 6 sekundi meri prvo vrednost sa jednog potenciometra, a zatim nakon 4 sekunde drugog, dok u šestoj sekundi računa razliku i zavisno od toga pali ili gasi potrošača. 
b) Koristi se jedan potenciometar za oba merenja - pri čemu je drugo merenje nakon 5 sekundi

NAPOMENA: Zadatak se radi individualno i nosi do 14 poena. Obavezno koristiti FreeRTOS. Veći broj poena dobijaju rešenja koja uspevaju da primene adekvatno tajmere i prekide tamo gde ima smisla. Pored kvaliteta rešenja, redosled predaje zadatka može uticati na broj poena.


Lab 1 (2025)
Napomena - radite samo jedan od zadataka, zavisno od vašeg broja indeksa! 
Maksimalan broj poena: 6

A)
Realizovati sistem koristeći Arduino Mega koji poseduje taster i tri diode. Uz pomoć prekida obezbediti da se svakim pritiskom pale diode na sledeći način: 1-pritisak: samo prva; 2-pritisak - prva i druga; 3-pritisak : sve tri; 4 -pritisak : sve ugašene; 5-pritisak: samo prva; 6-pritisak: prva i druga; 7-pritisakL sve tri... i tako dalje po datom šablonu.

B)
Realizovati sistem uz pomoć Arduino Mega koji poseduje taster i jednu diodu. Uz pomoć prekida obezbediti da se menja stanje sistema izmedju 3 rezima: 1-dioda upaljena 2-dioda blinka na 0.5s 3-dioda ugasena i tako dalje po ponavljajućem kružnom šablonu.

C)
Realizovati sistem koristeći Arduino Mega koji poseduje taster i tri diode. Uz pomoć pollinga obezbediti da se svakim pritiskom pale diode na sledeći način: 1-pritisak: samo prva; 2-pritisak - prva i druga; 3-pritisak : sve tri; 4 -pritisak : sve ugašene; 5-pritisak: samo prva; 6-pritisak: prva i druga; 7-pritisak sve tri... i tako dalje po datom šablonu.

Lab 2 (2025)
Napomena - radite samo jedan od zadataka, zavisno od vašeg broja indeksa! 
Maksimalan broj poena: 7

A)
Realizovati sistem koristeći Arduino Mega, SRF04 senzor i 6 LED dioda proizvoljne boje. Sistem simulira bacanje kockice za društvene igre - svake 3 sekunde se vrši proveri ako je rastojanje ruke od senzora manje od 5cm, generiše se nasumična vrednost od 1 do 6 i prikazuje paljenjem odgovarajućih LED dioda. Dobijena vrednost stoji prikazana sve dok se opet ne detektuje ruka na rastojanju manjem od 5cm.

B)
Realizovati sistem uz pomoć Arduino Mega, servo motora, dva tastera i jedne LED diode. Preko 2 interapta implementirati da tasteri obezbeđuju rotaciju motora u suprotnim smerovima. U slučaju dostizanja maksimalne rotacije u jednom od smerova, upaliti crvenu led diodu.

Lab 3 (2025)
Napomena - radite samo jedan od zadataka, zavisno od vašeg broja indeksa! 
Maksimalan broj poena: 7

A)
Realizovati uz pomoć Arduino Mega sistem koji uzima u obzir dva tastera povezana na proizvoljne pinove (logic state elementi su dozvoljeni) i zavisno od toga pali zelenu ili crvenu diodu. Ukoliko je vrednost prvog pina 1 -> pali se crvena LED dioda, a ukoliko se je vrednost drugog pina 1-> pali se zelena Za realizaciju koristiti FreeRTOS i taskove. Sistem ažurira stanje dioda svake 3 sekunde - prvo crvene, a zatim zelene i tako ciklično.

B)
Realizovati uz pomoć Arduino Mega sistem koji vrši decimalno dekodiranje vrednosti zadatih pomoću četiri tastera povezana na proizvoljne pinove (logic state elementi su dozvoljeni) i zavisno od toga prikazuje odgovarajuće cifre na LCD displeju.  Prva dva tastera kodiraju prvu cifru, a preostala dva drugu. Recimo, ako su vrednosti  01 10 -> LCD prikazuje 12, ako su 11 11 -> LCD prikazuje 33, za 00 00 -> 00 i slično. Za realizaciju koristiti FreeRTOS i taskove. Sistem ažurira stanje svake od cifara 3 sekunde - prvo za prva dva tastera, a zatim zelene i za druga dva, dok u međuvremenu pre ažuriranja za cifru stoji "X".

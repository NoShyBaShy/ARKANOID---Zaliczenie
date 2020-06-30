# Arkanoid - Grzegorz Blajer
Moim projektem na zaliczenie będzie gra typu Arkanoid.

### Opis
- Naszym celem jest sterować platformą tak, by odbijając opadającą piłkę, zniszczyć wszystkie bloki nad nami i nie dopuścić piłki do upadku. Bloki mają swoją wytrzymałość (potrzeba różnej liczby trafień by je zniszczyć). Ze zniszczonych bloków wypadają modyfikatory, które pomagają lub utrudniają (większa platforma, zmiana prędkości etc.). 

### Sterowanie i mechanika
- Sterumejmy platformą przy pomocy przycisków A oraz D. W momencie startu piłka porusza się z nami, co pozwala nam wybrac moment i miejsce startu. Naciskając Spację wypusczamy i nadajemy piłce prędkość platformy w osi X. Gdy wypuścimy ją w bezruchu piłeczka będzie poruszać się tylko w osi Y, co można zaklasyfikować jaką nieudaną próbę startu.
- Są 3 rodzaje bloków (czerwony, żółty, niebieski), które mają kolejno (1,2,3) punktów wytrzymałości.
- Z bloków może wypaść 9 różnych modifykatorów (S +/- to zmiana wielkości platformy, V +/- zmiana prędkości platformy, P +/- 1000pkt, czerwone/czarne serce zmiana liczby HP)
- Utworzone zostały 2 poziomy.
- Gra kończy się przy utraciu wszystkich żyć lub przejściu drugiego poziomu

### Biblioteki

- SFML (wersja z zajęć laboratoryjnych)

### Zasoby zewnętrzne

- Font : https://www.dafont.com/new-athletic-m54.font
- Background : https://www.spriters-resource.com/arcade/arkanoid/sheet/60811/
- Platform : https://www.spriters-resource.com/arcade/arkanoid/sheet/105879/

### GitHub

- https://github.com/NoShyBaShy/ARKANOID---Zaliczenie.git

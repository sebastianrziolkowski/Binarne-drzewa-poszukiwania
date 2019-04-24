# Wyniki testów

![alt text](https://raw.githubusercontent.com/sebastianrziolkowski/Binarne-drzewa-poszukiwania/master/Binarne%20drzewa%20poszukiwania.bmp)


# Binarne-drzewa-poszukiwania

<p>
Pewien podręcznik ma na końcu indeks haseł. Z każdym hasłem skojarzony jest wykaz stron, na których pojawia się dane hasło.
</p>
<p>
Zadanie polega na obsłudze indeksu haseł. Należy umożliwić dodanie nowego hasła, dodanie stron do hasła, usunięcie wybranych stron z hasła, sprawdzenie istnienia hasła na podanej stronie oraz wyświetlenie wykazu stron jednego hasła i wyświetlenie całego indeksu haseł.
</p>
<p> Hasła w wykazie mają być uporządkowane alfabetycznie, zaś strony rosnąco. W hasłach dopuszczane są tylko znaki alfabetu angielskiego (i tylko takie). Przez porządek alfabetyczny rozmumiemy kolejność leksykograficzną wg kodów ASCII. Numery stron są liczbami naturalnymi (>0). Każde hasło występuje w indeksie tylko raz. Numery stron w wykazie stron pojedynczego hasła także nie moga się powtarzać.
</p>
<p>
Strukturą, która ma umożliwiać realizację tego zadania mają być binarne drzewa wyszukiwania. Wymagamy własnej implementacji tych drzew. Binarne drzewa wyszukiwania mają być jedyną metodą dostępu do informacji w indeksie haseł.
</p>
<h3><font color=red>Uwaga dotycząca pojawiających się pytań i wątpliwości:</font></h3>
<p>Jedyną formą dostępu do informacji w indeksie haseł, tzn. <b>do haseł i do wykazu stron</b> mają być binarne drzewa wyszukiwania. Wymagana jest <b>własna</b> implementacja drzew przechowujących hasła, jak również drzew przechowujących strony. Tym samym nie można wykorzystywać gotowych struktur i algorytmów czyli np. jeżeli w rozwiązaniu jest potrzebny stos należy samodzielnie go zaimplementować.
<p><font color=red>Koniec uwagi.</font></p>

<h2>
Bardziej szczegółowy opis:
</h2>
<ul>
	<li>program w pierwszym wierszu otrzymuje liczbę instrukcji do wykonania,
	<li>następnie w każdym wierszu wejścia zapisana jest pojedyńcza instrukcja,
	<li>program powinien przetworzyć instrukcje jedna po drugiej. 
</ul>
<p>
Program powienien obsługiwać następujące instrukcje:
</p>
<ul>
	<li><b>I</b> - insert. Polecenie dodania do spisu hasła razem z wykazem stron tego hasła. Jeśli hasło istniało w spisie należy do wykazu jego stron dodać w odpowiednie miejsca jedynie te strony, które nie istniały jeszcze w tym wykazie.
	<li><b>D</b> - delete. Program usuwa strony w wykazie stron podanego hasła. Jeżeli hasło nie posiada już żadnych stron należy usunąć całe hasło.
	<li><b>F</b> - find.  Program sprawdza, czy podane hasło występuje na zadanej stronie. Zwraca 1 gdy podane hasło wystepuje na stronie, zaś 0 w przypadku braku hasła lub gdy nie ma hasła na podanej stronie.
	<li><b>A</b> - find all. Program wydaje hasło oraz wszystkie strony, na których występuje podane hasło lub -1, gdy nie ma w indeksie takiego hasła.
	<li><b>P</b> - print. Wyświetlenie całego wykazu w określonym formacie: <pre>hasło spacja numery_stron_rozdzielone_spacjami endline</pre> Hasła mają być posortowane alfabetycznie, zaś strony wyświetlone w porządku rosnącym.
</ul>
<h2>Formaty poleceń:</h2>
<ul>
<li><pre>I etykieta liczbaStron strona1 strona2...</pre>
Na początku jest hasło, potem liczba stron, które wstawiamy, a następnie numery stron odzielone spacjami. Strony są nie muszą być posortowane.
<li><pre>D etykieta liczbaStron strona1 strona2...</pre>
Na początku jest hasło, potem liczba stron, które należy usunąć, a następnie numery stron oddzielone spacjami. Strony nie muszą być posortowane. <br>
W przypadku, gdy podana strona nie znajduje się w wykazie stron dla danego hasła, program ignoruje usunięcie tej strony. Również w przypadku próby usunięcia nieistniejącego hasła program nie wykonuje żadnej akcji.
<li><pre>F etykieta strona</pre>
<li><pre>A etykieta</pre>
<li><pre>P</pre>
</ul>


<h2>Formaty wyników:</h2>
<ul>
	<li><tt>F</tt> - zwraca 0 lub 1
	<li><tt>A</tt> - zwraca: <pre>haslo strona1 strona2...</pre> lub -1, gdy  nie ma takiego hasła. Strony mają być wyświetlone w porządku rosnącym.
	<li><tt>P</tt> - Wyświetla cały indeks haseł w wymaganym formacie. Każde hasło wyświetlane jest w jednym wierszu w następującej postaci: 
<pre>hasło spacja strony_po_spacjach</pre> 
Hasła mają być posortowane alfabetycznie, zaś numery stron rosnąco. Jeżeli indeks nie zawiera żadnego hasła program nic nie wyświetla.
</ul>

<h2>Przykład 1</h2>
<h4>Wejście</h4>
<pre>
4
I Adam 3 12 5 8
I Adrian 2 45 78
I Adam 2 5 9
P
</pre>
<h4>Wyjście:</h4>
<pre>
Adam 5 8 9 12
Adrian 45 78
</pre>
<h2>Przykład 2</h2>
<h4>Wejście</h4>
<pre>
6
I Adam 3 12 5 8
I Adrian 2 45 78
I Adam 2 5 9
D Adam 1 9
P
F Adam 8
</pre>
<h4>Wyjście:</h4>
<pre>
Adam 5 8 12
Adrian 45 78
1
</pre>


<h2>Przykład 3</h2>
<h4>Wejście</h4>
<pre>
14
I Adam 4 12 34 56 87
I Adrian 3 12 23 55
I Adam 3 12 14 38
D Adrian 1 12
A Adam
F Adrian 12
P
I Cdrian 2 56 8
F Cdrian 8
P
D Cdrian 3 56 8 90
F Cdrian 8
P
A Cdrian
</pre>

<h4>Wyjście:</h4>
<pre>
Adam 12 14 34 38 56 87
0
Adam 12 14 34 38 56 87
Adrian 23 55
1
Adam 12 14 34 38 56 87
Adrian 23 55
Cdrian 8 56
0
Adam 12 14 34 38 56 87
Adrian 23 55
-1
</pre>

Zadanie pochodzi z kursu uczelni UMCS tichy.umcs.lublin.pl

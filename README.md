# ProportionalParliament
A look at a parliamentary system that is fully proportional.

After going through the 2016 US elections and 2017 UK elections, I decided to look at what a parliamentary
system would look like if the various parties were given proportional representation, based of percentage of
votes.

The program takes a file as a command line parameter containing the needed info. It is in the form:

<Number of Seats>
<Party Name1> <Num Votes>
...
<Party NameN> <Num Votes>

It then calculates seats based on percentage. The cutoff to be considered for seats is now .09%. 

The methodology is to determine seats. It stops giving out seats when the parliament is full. It allocates highest % down to lowest . If the lowest should be allocated more seats than are in the parliament, its seats are cut short.

i.e.

100 seats, the current total after divying up seats is 98. PartyX should get 5 seats. However, this would make it 103 seats. Thus, PartyX would only get 2 seats.

Also, if, after the threashold, there are less seats. Additional seats are allotted in a circular fashion.

i.e.

100 seats
PartyA = 40 seats
PartyB = 20 seats
PartyC = 15 seats
PartyD = 15 seats
PartyE = 5 seats
PartyF = 1 seat
Total = 96

Parties A through D would get allotted one more. Seats get added until it is full. It will add a seat from A to F, and start back at A, if needed.

Makefile is included. C++11 is used. Not tested in Windows.

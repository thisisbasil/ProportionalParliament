# ProportionalParliament
A look at a parliamentary system that is fully proportional.
    Copyright (C) 2017 Basil Huffman

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    This applies to all source in this package.

After going through the 2016 US elections and 2017 UK elections, I decided to look at what a parliamentary
system would look like if the various parties were given proportional representation, based of percentage of
votes.

The program takes a file as a command line parameter containing the needed info. It is in the form:



[Number of Seats]

[Party Name1] [Num Votes]

...

[Party NameN] [Num Votes]

Empty lines and lines commented out with the pound sign (#) are disregarded.


It uses the strategy design pattern, so a number of different strategies. The one used will be documented in circprop.h.

Download all files into a directory and just make.

Hasn't been tested in Windows. If someone wants to try and post an executable, feel free.

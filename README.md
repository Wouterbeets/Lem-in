Lem-in
======

42

Oke lets make a plan:
for lem-in
	the basic structure is going to be a linked list item with a linked lists 
	nested inside

##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 3 9
6 1 0
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
6-5.

is the input:

we will have to read it from the standard entree;
get_next_line will work fine.
comments can be ignored.
except for start and end.(double #)
posistioning of the items can be ignored for version 1.0 but should be saved
for in the list node for when we want to make a visual rep.

structure of the list is as folows

typedef struct s_room;
{
	struct s_connect		*connect;
	int						num_of_lem;
	char					*id;
	int						posx;
	int						posy;
	int						is_start;
	int						is_end;
	struct s_rooms			*next;
}				t_room;

typedef struct s_connect
{
	struct s_connect	next;
	struct s_room		connected_room;
}

functions needed:

t_room		**ft_get_data()
{
	\\get_next_line until at connections;
	for every room create a list item in a simple list; t_room;
	save the data for every list in t_room;

	when get_next_line returns "X-X" switch to af functions that searches the list
	t_room for the the two items seperated by '-' and ads a ellemnt in each of them
	pointing to the other;
}



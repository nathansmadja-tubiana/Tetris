#include "piece.h"

/* Display a piece
*   param Piece the piece to display
*/
void displayPiece(Piece p) {
	for (int i = 0; i < p.height; i++){
		printf("%s \n", p.shape[i]);
	}
}

/* Display the list of pieces horizontally
*   param Piece[] the list to display
*/
void displayPieceChoice(Piece list[4]) {
	// To display all the pieces on the same line,
	// we need to compute the height of the biggest piece
	// for correct alignment
	int max_height = 0;
	for (int i = 0; i < 4; i++) {
		if (list[i].height > max_height) {
			max_height = list[i].height;
		}
	}
	
	// We display all pieces line by line
	for (int j = 0; j < max_height; j++) {
		// Display the line of numbers used for the orientation choice
		if (j==0) {
			for (int l = 0; l < 4; l++) {
				printf(" %d   ", l+1);
				// Small shift to keep everything aligned
				if (l == 2) {
					printf(" ");
				}
			}
			printf("\n");
		}
		
		color(list[0].color);
		for (int i = 0; i < 4; i++) {
			// If the piece is too short, we display an empty string
			if (list[i].height - 1 < j) {
				printf("      ");
			} else {
				printf("%s  ", list[i].shape[j]);
				// Small shift to keep everything aligned
				if (!(i < 2 && j == 0 && max_height == 4)) {
					printf(" ");
				}
			}
		}
		color(0);
		printf("\n");
	}
}

/* Ask the orientation the piece should have
*   param Piece[] the list of possibilities
*   return Piece the choosen piece
*/
Piece choosePiece(Piece list[4]) {
	//for (int i = 0; i < 7; i++) {
	// Choose a random piece
	displayPieceChoice(list);
	printf("\n");
	//}
	
	int choice = -1, valid = 1;
	char trash;
	do {
		if (!valid) {
			printf("Input non valide\n");
		}

		printf("Orientation de la pièce :\n");
		// Empty the input buffer if invalid input
		if (scanf("%d",&choice) == 0) {
			while((trash = getchar()) != '\n' && trash != EOF);
		}
		valid = 0;
	} while (choice < 1 || choice > 4);
	choice --;
	return list[choice];
}

/* Create all pieces
*   param Piece[][] the array to save pieces
*/
void setTabPiece(Piece tabPiece[7][4]){
	Piece a;
	a.color = 31;
	a.height = 2;
	a.width = 3;
	a.shape = malloc(sizeof(char*)*a.height);
	a.shape[0] = "@@@";
	a.shape[1] = " @ ";
	tabPiece[0][0] = a;
	Piece b;
	b.color = 31;
	b.height = 3;
	b.width = 2;
	b.shape = malloc(sizeof(char*)*b.height);
	b.shape[0] = "@ ";
	b.shape[1] = "@@";
	b.shape[2] = "@ ";
	tabPiece[0][1] = b;
	Piece c;
	c.color = 31;
	c.height = 2;
	c.width = 3;
	c.shape = malloc(sizeof(char*)*c.height);
	c.shape[0] = " @ ";
	c.shape[1] = "@@@";
	tabPiece[0][2] = c;
	Piece d;
	d.color = 31;
	d.height = 3;
	d.width = 2;
	d.shape = malloc(sizeof(char*)*d.height);
	d.shape[0] = " @";
	d.shape[1] = "@@";
	d.shape[2] = " @";
	tabPiece[0][3] = d;
	
	Piece e;
	e.color = 32;
	e.height = 1;
	e.width = 4;
	e.shape = malloc(sizeof(char*)*e.height);
	e.shape[0] = "@@@@";
	tabPiece[1][0] = e;
	Piece f;
	f.color = 32;
	f.height = 4;
	f.width = 1;
	f.shape = malloc(sizeof(char*)*f.height);
	f.shape[0] = "@";
	f.shape[1] = "@";
	f.shape[2] = "@";
	f.shape[3] = "@";
	tabPiece[1][1] = f;
	Piece e2;
	e2.color = 32;
	e2.height = 1;
	e2.width = 4;
	e2.shape = malloc(sizeof(char*)*e2.height);
	e2.shape[0] = "@@@@";
	tabPiece[1][2] = e2;
	Piece f2;
	f2.color = 32;
	f2.height = 4;
	f2.width = 1;
	f2.shape = malloc(sizeof(char*)*f2.height);
	f2.shape[0] = "@";
	f2.shape[1] = "@";
	f2.shape[2] = "@";
	f2.shape[3] = "@";
	tabPiece[1][3] = f2;
	
	Piece g;
	g.color = 33;
	g.height = 2;
	g.width = 3;
	g.shape = malloc(sizeof(char*)*g.height);
	g.shape[0] = "@@@";
	g.shape[1] = "@  ";
	tabPiece[2][0] = g;
	Piece h;
	h.color = 33;
	h.height = 3;
	h.width = 2;
	h.shape = malloc(sizeof(char*)*h.height);
	h.shape[0] = "@ ";
	h.shape[1] = "@ ";
	h.shape[2] = "@@";
	tabPiece[2][1] = h;
	Piece i;
	i.color = 33;
	i.height = 2;
	i.width = 3;
	i.shape = malloc(sizeof(char*)*i.height);
	i.shape[0] = "  @";
	i.shape[1] = "@@@";
	tabPiece[2][2] = i;
	Piece j;
	j.color = 33;
	j.height = 3;
	j.width = 2;
	j.shape = malloc(sizeof(char*)*j.height);
	j.shape[0] = "@@";
	j.shape[1] = " @";
	j.shape[2] = " @";
	tabPiece[2][3] = j;
	
	Piece k;
	k.color = 34;
	k.height = 2;
	k.width = 3;
	k.shape = malloc(sizeof(char*)*k.height);
	k.shape[0] = "@@@";
	k.shape[1] = "  @";
	tabPiece[3][0] = k;
	Piece l;
	l.color = 34;
	l.height = 3;
	l.width = 2;
	l.shape = malloc(sizeof(char*)*l.height);
	l.shape[0] = "@@";
	l.shape[1] = "@ ";
	l.shape[2] = "@ ";
	tabPiece[3][1] = l;
	Piece m;
	m.color = 34;
	m.height = 2;
	m.width = 3;
	m.shape = malloc(sizeof(char*)*d.height);
	m.shape[0] = "@  ";
	m.shape[1] = "@@@";
	tabPiece[3][2] = m;
	Piece n;
	n.color = 34;
	n.height = 3;
	n.width = 2;
	n.shape = malloc(sizeof(char*)*n.height);
	n.shape[0] = " @";
	n.shape[1] = " @";
	n.shape[2] = "@@";
	tabPiece[3][3] = n;
	
	Piece o;
	o.color = 35;
	o.height = 2;
	o.width = 2;
	o.shape = malloc(sizeof(char*)*o.height);
	o.shape[0] = "@@";
	o.shape[1] = "@@";
	tabPiece[4][0] = o;
	Piece o2;
	o2.color = 35;
	o2.height = 2;
	o2.width = 2;
	o2.shape = malloc(sizeof(char*)*o.height);
	o2.shape[0] = "@@";
	o2.shape[1] = "@@";
	tabPiece[4][1] = o2;
	Piece o3;
	o3.color = 35;
	o3.height = 2;
	o3.width = 2;
	o3.shape = malloc(sizeof(char*)*o.height);
	o3.shape[0] = "@@";
	o3.shape[1] = "@@";
	tabPiece[4][2] = o3;
	Piece o4;
	o4.color = 35;
	o4.height = 2;
	o4.width = 2;
	o4.shape = malloc(sizeof(char*)*o.height);
	o4.shape[0] = "@@";
	o4.shape[1] = "@@";
	tabPiece[4][3] = o4;
	
	Piece p;
	p.color = 36;
	p.height = 2;
	p.width = 3;
	p.shape = malloc(sizeof(char*)*p.height);
	p.shape[0] = " @@";
	p.shape[1] = "@@ ";
	tabPiece[5][0] = p;
	Piece q;
	q.color = 36;
	q.height = 3;
	q.width = 2;
	q.shape = malloc(sizeof(char*)*q.height);
	q.shape[0] = "@ ";
	q.shape[1] = "@@";
	q.shape[2] = " @";
	tabPiece[5][1] = q;
	Piece p2;
	p2.color = 36;
	p2.height = 2;
	p2.width= 3;
	p2.shape = malloc(sizeof(char*)*p2.height);
	p2.shape[0] = " @@";
	p2.shape[1] = "@@ ";
	tabPiece[5][2] = p2;
	Piece q2;
	q2.color = 36;
	q2.height = 3;
	q2.width = 2;
	q2.shape = malloc(sizeof(char*)*q2.height);
	q2.shape[0] = "@ ";
	q2.shape[1] = "@@";
	q2.shape[2] = " @";
	tabPiece[5][3] = q2;
	
	Piece r;
	r.color = 37;
	r.height = 2;
	r.width = 3;
	r.shape = malloc(sizeof(char*)*r.height);
	r.shape[0] = "@@ ";
	r.shape[1] = " @@";
	tabPiece[6][0] = r;
	Piece s;
	s.color = 37;
	s.height = 3;
	s.width = 2;
	s.shape = malloc(sizeof(char*)*s.height);
	s.shape[0] = " @";
	s.shape[1] = "@@";
	s.shape[2] = "@ ";
	tabPiece[6][1] = s;
	Piece t;
	t.color = 37;
	t.height = 2;
	t.width = 3;
	t.shape = malloc(sizeof(char*)*t.height);
	t.shape[0] = "@@ ";
	t.shape[1] = " @@";
	tabPiece[6][2] = t;
	Piece u;
	u.color = 37;
	u.height = 3;
	u.width = 2;
	u.shape = malloc(sizeof(char*)*u.height);
	u.shape[0] = " @";
	u.shape[1] = "@@";
	u.shape[2] = "@ ";
	tabPiece[6][3] = u;
}
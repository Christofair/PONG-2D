


#include "AI.h"

AiTreeNode::AiTreeNode()
{
	up = nullptr;
	middle = nullptr;
	down = nullptr;
	/*a_before = silnik.get_a();
	a_before = silnik.get_b();*/
}

/*Tworzy kolejne elementy dla zadanych wartosci*/
AiTreeNode::AiTreeNode(int a_before, int b_before, int rotation_before, bool who)
{
	up = nullptr;
	middle = nullptr;
	down = nullptr;
	this->a_before = a_before;
	this->b_before = b_before;
	this->rotation_before = rotation_before;
	this->who = who;


}
/*Oblicza docelowe miejsce pilki 
ustawia zmienne BallTargetPosition*/
void AiTreeNode::CalculateBallTargetPosition()
{
	//kod z silnika
}

/*Oblicza zmienne pi�ki po odbiciu od danej rakietki
ustawia a_after, b_after_ rotation_after
*/
void AiTreeNode::CalculateBallParams()
{
	
	int bs = 50;
	int br = 15;
	this->speed_after = this->speed_before + 2 * bs;
	if (this->rotation_before == 0) this->rotation_after = this->rotation_before - (me*br);//pi�ka bez rotacji
	if (this->rotation_before != 0)// pi�ka z rotacja
	{
		if ((me = 1 && this->rotation_before > 0) || (me = -1 && rotation_before < 0))
		{
			this->rotation_after = this->rotation_before + me * br;//zwieksza bezwgledn� warto�� wspolczynnika rotacji
		}
		else
		{
			this->rotation_after = this->rotation_before - me * br;//zmniejsza bezwgledn� warto�� wspolczynnika rotacji
		}

	}
	if (this->speed_before > 1000) this->speed_after = 1000;//nie przekraczanie wartosci maksymalnej
	if (this->rotation_after > 100) this->rotation_after = 100;//////
	if (this->rotation_after < -100) this->rotation_after = -100;////
}

/*Sprawdza czy uda si� odbi� pi�k�
ustawia zmienne can, MyDistance, MyTargetPosition*/
void AiTreeNode::CanIBounceBall()
{
	//szybko�� rakietki+dlugo��

}

void AiTreeNode::CreateNextLevel()
{
	up = new AiTreeNode(a_after, b_after, rotation_after, !(this->who));
	middle = new AiTreeNode(a_after, b_after, rotation_after, !(this->who));
	down = new AiTreeNode(a_after, b_after, rotation_after, !(this->who));

}

AiTreeNode* create_root()
{

	AiTreeNode* root;
	
	//TODO pobierz zmienne o locie z silnika
	root = new AiTreeNode(1,1,0, AiBounce);//pobierz zmienne z silnika
	return root;
}


AiTreeNode::~AiTreeNode()//destruktor drzewa
{
	if (up != nullptr)
		delete up;
	if (middle != nullptr)
		delete middle;
	if (down != nullptr)
		delete down;
}
AiTreeNode* AiTreeNode::get_child(char part)
{
	switch (part)
	{
	case part_up: return up;
	case part_middle: return middle;
	case part_down: return down;
	}

}


bool AiTreeNode::get_can()
{
	return this->can;
}

unsigned AiTreeNode::getMydistance()
{
	return this->MyDistance;
}

unsigned AiTreeNode::getBallTarget()
{
	return this->BallTargetPosition;
}

void AI::StartAI()
{
	/*AiTreeNode* root = create_root();
	root->CalculateBallTargetPosition();
	root->CanIBounceBall();

	if (root->get_can())
	{
		root->CreateNextLevel();
		root->get_child(part_up)->CalculateBallParams();
		root->get_child(part_up)->CalculateBallTargetPosition();
		
		root->get_child(part_middle)->CalculateBallParams();
		root->get_child(part_middle)->CalculateBallTargetPosition();
	

		root->get_child(part_down)->CalculateBallTargetPosition();
		root->get_child(part_down)->get_can();

		if (root->get_child(part_up)->getMydistance() > root->get_child(part_middle)->getMydistance())
		{
			if (root->get_child(part_up)->getMydistance() > root->get_child(part_down)->getMydistance())
				//setPaletka(root->getBallTarget+paletka.getDlugosc()/3)
			else
				//setPaletka(root->getBallTarget-paletka.getDlugosc()/3)
		}

	}

	*/
}








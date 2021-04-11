#ifndef _NUCLEARALERT_OUVRIER_HPP_
#define _NUCLEARALERT_OUVRIER_HPP_


class ouvrier
{
	public:
		ouvrier();

		int get_etat() const;
		void set_etat(const int etat);
		int get_dispo() const;
		void set_dispo(const int dispo);

	protected:
		int etat;
		int dispo;

};

#endif

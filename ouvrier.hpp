#ifndef _NUCLEARALERT_OUVRIER_HPP_
#define _NUCLEARALERT_OUVRIER_HPP_


class ouvrier
{
	public:
		ouvrier();

		double get_etat() const;
		void set_etat(const int etat);
		bool get_dispo() const;
		void set_dispo(bool dispo);

	protected:
		int etat;
		bool dispo;

};

#endif

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <cmath>

using namespace std;

void	get_that_r_ery_xary_kongruent(int n0, int lambda, int m, int myu);
// void	get_that_r_ery_kongruent(int n0, int lambda, int m);
int check_vor_spasarkman_kabinetna_azat(double mutq_ti[], int i, const int N, double t_azatum[]);
double find_min_value_of_t_azatum(double t_azatum[], const int N, int *index);
void    dvijenin_skvav(double mutq_ti[], double spasum_ti[], double spasarkum_ti[], int hayteri_qanak, const double T);
int mutq(double mutq_ti[], double arr_r[], const double T, int count);
void spasum(double spasum_ti[], double arr_r[], int *count, const double T, int hayteri_qanak);
void	spasarkum(double spasarkum_ti[], double arr_r[], int hayteri_qanak);

int main()
{
    int n0;

    cout << "n0 = ";
    cin >> n0;
    while (!(n0 > 0 && n0 % 2 == 1))
    {
        cout << "n0 = ";
        cin >> n0;
    }
	int myu;
	do {cout << "myu = ";cin >> myu;}
	while (myu <= 0);
	int k = 6;//vor r-ery 32hat stanam
    int lambda;
    int sign;
    do
	{
		cout << "please write only + or - \nNote:+ is 1, - is -1\n";
    	cin >> sign;
	}while (!(sign == 1 || sign == -1));
	// {
	// 	cout << "please write only + or - \nNote:+ is 1, - is -1\n";
    // 	cin >> sign;
	// }
    int t;
	do {cout << "t = ";cin >> t;}
	while (t < 1);

    switch(sign)
    {
        case(1):
            lambda = 8 * t + 3;
            break;
        case(-1):
            lambda = 8 * t - 3;
            break;
        default:
            cout << "incorrect sign";
            break;
    }
	int m = pow(2, k);
	get_that_r_ery_xary_kongruent(n0 ,lambda, m, myu);
    // get_that_r_ery_kongruent(n0 ,lambda, m);
}

void	get_that_r_ery_xary_kongruent(int n0, int lambda, int m,int myu)
{
	double arr_r[10000];
	int ni = -1;
	int temp = n0;
	int count = 0;
	cout << n0 << " "<< " "<< lambda << " "<< m;
	for (int i = 0; ni != n0; i++)
	{
		ni = (temp * lambda + myu) % m;
		arr_r[i] = (double)ni / m;
		// cout << "n = " << ni << endl;
		cout << "r[" << i << "]= " << arr_r[i] << endl;
		temp = ni;
		count++;
	}
	// int h = count;
	// cout << "h = " << h << endl;
    cout  << "stex count = " << count << endl;
    const double T = 150.0;
    double	mutq_ti[1000];//muqti t-erna//amen tarr iranic nerkayacnuma tvyal i-rd hayti skzbi jmky
	int hayteri_qanak = mutq(mutq_ti, arr_r, T, count);
    double	spasum_ti[1000];//spasman t-erna
    spasum(spasum_ti, arr_r, &count, T, hayteri_qanak);
	double	spasarkum_ti[1000];
    spasarkum(spasarkum_ti, arr_r, hayteri_qanak);
    dvijenin_skvav(mutq_ti, spasum_ti, spasarkum_ti, hayteri_qanak, T);
}

double find_min_value_of_t_azatum(double t_azatum[], const int N, int *index)
{
    double min = t_azatum[0];
    *index = 0;
    int i = 0;
    while (i < N)
    {
        if (t_azatum[i] < min)
        {
            *index = i;
            min = t_azatum[i];
        }
        i++;
    }
    return (min);
}

int check_vor_spasarkman_kabinetna_azat(double mutq_ti[], int i, const int N, double t_azatum[])
{
    int j = 0;
    while (j < N)
    {
        cout << "ekav = " << mutq_ti[i]<< endl;
        cout << "isk -> "<< t_azatum[j]<< " " << endl;
        if (mutq_ti[i] >= t_azatum[j])
            return (j);
        j++;
    }
    return (-1);
}


void    dvijenin_skvav(double mutq_ti[], double spasum_ti[], double spasarkum_ti[], int hayteri_qanak, const double T)
{
    cout << T<<endl;
    cout << "ola";
    int ch = 0;//chspasarkvacneri arrayi index
    int chspasarkvac[100];
    int s = 0;
    int spasarkvac[100];
    const int N = 2;
    double t_azatum[N] = {0};
    int i = 0;
    int j;
    double min;
    int index;//te vor kabinetna zbaxvacneric arajiny azatvelu
    while (i < hayteri_qanak)
    {
        j = check_vor_spasarkman_kabinetna_azat(mutq_ti, i ,N, t_azatum);
        if (j != -1)
        {
            t_azatum[j] = mutq_ti[i] + spasarkum_ti[i];
            cout << "spasarkvec =>" << j << "-um" << endl;
            cout << "t_azatum [" << j << "] = " << t_azatum[j] << endl;
            if (t_azatum[j] <= T)
                spasarkvac[s++] = i;
            else
            {
                chspasarkvac[ch++] = i;
                break;
            }
        }
        else if (j == -1)//nsh. e vor azat kabinet chka ,tenanq ira spasely ogurt kta vor spasarkvi te champenq eta
        {
            min = find_min_value_of_t_azatum(t_azatum, N, &index);//gtnenq amenashut azatvox kabinety
                cout << "shut kazatvi = "<< min <<"index = " <<index<< endl;
            if (mutq_ti[i] + spasum_ti[i] <= min)//kam zut poqr
            {
                cout << "cavoq dzer spasely ogtum chi,polyubomu duq merjvelu eq ' cheq spasarlvelu" << endl;
                chspasarkvac[ch++] = i;
                //senc depq chuneca,chem stuge
            }
            else
            {
                t_azatum[index] = mutq_ti[i] + (t_azatum[index] - mutq_ti[i]) + spasarkum_ti[i];
                cout << "yhnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn ->" << t_azatum[index]<< "index = "<< index<<endl;
                if (t_azatum[index] <= T)
                    spasarkvac[s++] = i;
                else
                    break ;
            }
        }
        i++;
    }


    cout << "ch = " << ch<<endl;
    cout << "s = " << s<<endl;
    int c= 0 ;
    while (c < ch)
    {
        cout << "chhres = "<<chspasarkvac[c] << endl;
        c++;
    }
    c= 0 ; 
    while (c < s)
    {
        cout << "hres = "<<spasarkvac[c] << endl;
        c++;
    }
}

int mutq(double mutq_ti[], double arr_r[], const double T, int count)
{
    // cout << "&? = " << count;
	const int a = 4;
	const int b = 8;
	int	t0 = 0;
	// double	mutq_ti[1000];//muqti t-erna//amen tarr iranic nerkayacnuma tvyal i-rd hayti skzbi jmky
	// arr_ti[0] = 0;
	double arr_tau[1000];
	int i = 0;
    mutq_ti[0] = 0;
    double temp = mutq_ti[0];
	while(temp < T && i < count)//nra hamar vor r-ery karoxa prcac lini bayc der temp poqr ylni T-ic
	{
		// cout << "eee" << endl;
		arr_tau[i] = a + (b - a) * arr_r[i];
		if (i == 0)
			mutq_ti[i] = 0 + arr_tau[i];
		else
        {
            if(mutq_ti[i - 1] + arr_tau[i] < T)
                mutq_ti[i] = mutq_ti[i - 1] + arr_tau[i];
            else
                break;
        }
        cout << "mutqi ti = " << mutq_ti[i] << endl;
        temp = mutq_ti[i];
		i++;
	}
	int hayteri_qanak = i;//i - 1 che vortev mer mot i-n 0-ica sksvum
	cout << "qanak = " << hayteri_qanak << endl;
    return (hayteri_qanak);
}

void spasum(double spasum_ti[], double arr_r[], int *count, const double T, int hayteri_qanak)
{
    double ri_sum ;
    const int myu = 7;
	const int sigma = 2;
    // double	spasum_ti[1000];//spasman t-erna
    int i = 0;
    int j = 0;
    spasum_ti[0] = 0;
    double temp = spasum_ti[i];
    // cout << "hasanq\n";
    while(hayteri_qanak)
    {
        ri_sum = 0;
        j = i;
    // cout << "count = "<< *count << endl;
        while (j < (12 + i))//2rd paymany nra hamara,vor karoxa ev en verevi while hly chishta aysinqn et T-in der chemq hase(ete iharke paymany chisht em dre,et pahy harcnel????),bayc karoxa arr_r-ers chheriqen(32 hat en)
        {
            // cout << "blin";
            ri_sum += arr_r[j];
            // cout << "sum  = " << ri_sum << " ";
            // cout << "arr_r = " << arr_r[j] << " ";
            j++;
        }
        // cout << "ri+sum = "<<ri_sum << endl;
        // if (!(i + 12 <= *count))
        // {
        //     cout << "j = " << j<<endl;
        //     cout << "pahooo\n";
        //     break ;
        // }
        spasum_ti[i] = myu + (sigma * (ri_sum - 6));
        cout << "spasman ti = " << spasum_ti[i] << endl;
        temp = spasum_ti[i];
        i++;
        // cout << "coooooount = " <<*count << endl;
        hayteri_qanak--;
    }
    cout << "i = " << i << endl;
}

void	spasarkum(double spasarkum_ti[], double arr_r[], int hayteri_qanak)
{
	int i = 0;
	const double lambda = 0.2;
	// double	spasarkum_ti[1000];
	 while(hayteri_qanak)
    {
        spasarkum_ti[i] = (-1 / lambda) * log(arr_r[i]);
        cout << "spasarkum ti = " << spasarkum_ti[i] << endl;
        i++;
        hayteri_qanak--;
    }
    cout << "i = " << i << endl;
}
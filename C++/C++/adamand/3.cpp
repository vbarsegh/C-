#include<iostream>
#include<fstream>
#include<stdio.h>
#include<unistd.h>

class General
{
    protected:
        General()
        {
            std::cout << "General ctor is called" << std::endl;
        }
    public:
        size_t  get_size_obj() const {return (sizeof(*this));}
};

class GeomSerialize : virtual public General
{
    protected:
        bool fl_saved  =false ;
    public:
        GeomSerialize()
        {
            std::cout << "GeomSerialize ctor is called" << std::endl;
        }
        virtual void save(std::ostream& os) const = 0;
        virtual void load(std::istream& is) = 0;
        // size_t  get_size_obj() const {return (sizeof(*this));}
        virtual ~GeomSerialize()
        {
            std::cout << "GeomSerialize dtor is called" << std::endl;
        }
};

class GeomBase : virtual public General
{
    protected:
        int x{0}, y{0}, x1{0}, y1{0};
    public:
        GeomBase(int a = 0, int b = 0, int c = 0, int d = 0) :x(a), y(b), x1(c), y1(d)
        {
            std::cout << "GeomBase ctor is called" << std::endl;
        }
        virtual void draw() const = 0;
        virtual ~GeomBase()
        {
            std::cout << "GeomBase dtor is called" << std::endl;
        }
        // size_t  get_size_obj() const {return (sizeof(*this));}
};

class Line : public GeomBase, public GeomSerialize
{
    private:
        double length{0.0};
    public:
        Line(int a = 0, int b = 0, int c = 0, int d = 0) : GeomBase(a,b,c,d), GeomSerialize() 
        {
            std::cout << "Line ctor is called" << std::endl;
        }
        virtual void draw() const override
        {
            printf("Line: %d, %d, %d, %d\n", x, y, x1, y1);
        }
        virtual void save(std::ostream& os) const override
        {
            os.write((char *)this, sizeof(*this));
        }
        virtual void load(std::istream& is) override
        {
            is.read((char *)this, sizeof(*this));
        }
        ~Line()
        {
            std::cout << "Line dtor is called" << std::endl;
        }
};

int main()
{
    Line ln(1,2,10,20);

   General chobj;//tes vor  asuma ches karastexces,vortev ctory protected a
}

//qani vor imast chhka arandzin stexcel Generali,geombase-i ev GeomSerialize-i obyektner(GeomBase-i ev GeomSerialize-i hamar apahovaca vor chkarananq stexcenq vortev iranq abstrakt class en(parunakum en maqur virtual funckia(ner))),Generali pahy kapahovenq hetevyal kerp`
// nra ctor-@ kqcenq protected sekciayi mej,inchu protected ayl vochte privatre,vortev gitenq vor jarangi hamar protected-@ darnum public isk drsi`client kodi hamar private,esel arvuma nra hamar vor uzenanq jarang dasi obyekt stexcenq karenanq,vortev jaramg obyekt stexcelu hamar nax ev araj pti stexcven ira base clasneri obyektnery
//itogum Generali ctriy protected sekciayum qcelov chenq karum zut ira obyekt stexcenq bayc jarang clasi obyekt stexcel klni(ete private liner etel cher stacvi)

//sranov sovorecinq evs mek metod abstrakt classic baci, vor zut ira tipi obyekt chenq kara stexcenq,zut ctory protected fdnelov
#ifndef _VTASKAS_H_
#define _VTASKAS_H_

class VardinisTaskas3D{
   private:
      char*  vardas_;
      char*  info_;
      double x_;
      double y_;
      double z_;

   public:
      VardinisTaskas3D(char* vardas, char* info, double x, double y, double z);
      VardinisTaskas3D(VardinisTaskas3D &src);
      void rodykTaska() const;
      void keiskVarda(const char* naujas);
      void keiskInfo(const char* kitas);
      void rodykKoordinates();
      void keiskVieta(const double x, const double y, const double z);
      double atstumasIkiKito(const VardinisTaskas3D& kitas) const;

	  void setX(double newX);
	  void setY(double newY);
	  void setZ(double newZ);

      double getX();
      double getY();
      double getZ();
      char *getName();
      char *getInfo();
      ~VardinisTaskas3D();
};
#endif

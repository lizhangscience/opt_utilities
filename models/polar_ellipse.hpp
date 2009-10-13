#ifndef PELLIPSE_MODEL_H_
#define PELLIPSE_MODEL_H_
#define OPT_HEADER
#include <core/fitter.hpp>
#include <cmath>

namespace opt_utilities
{
  template <typename T>
  class polar_ellipse
    :public model<T,T,std::vector<T>,std::string>
  {
  private:
    model<T,T,std::vector<T> >* do_clone()const
    {
      return new polar_ellipse<T>(*this);
    }
  public:
    polar_ellipse()
    {
      this->push_param_info(param_info<std::vector<T> >("a",1,0,10));
      this->push_param_info(param_info<std::vector<T> >("e",0,0,1));
      this->push_param_info(param_info<std::vector<T> >("theta0",0,0,360));
    }

  public:
    T do_eval(const T& x,const std::vector<T>& param)
    {
      double a=param[0];
      double e=param[1];
      double t0=param[2];
      double t=x-t0;
      t=t/180.*3.14159265358979;
      return a*(1-e*e)/(1-e*cos(t));
    }

  private:
    std::string do_to_string()const
    {
      return "linear model\n"
	"y=k*x+b\n";
    }
  };
}



#endif
//EOF

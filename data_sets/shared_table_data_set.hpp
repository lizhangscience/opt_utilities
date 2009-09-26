/**
   \file default_data_set.hpp
 */

#ifndef SHARED_TABLE_DATA_SET
#define SHARED_TABLE_DATA_SET
#define OPT_HEADER
#include "core/fitter.hpp"
#include <vector>


namespace opt_utilities
{

  /**
     \brief shared_table implement of the data set
     \tparam Ty type of y
     \tparam Tx type of x
   */
  template <typename Ty,typename Tx>
  class shared_table_data_set
    :public data_set<Ty,Tx>
  {
    //  private:
  public:
    std::vector<data<Ty,Tx> > data_vec;
    
    data_set<Ty,Tx>* do_clone()const
    {
      return (data_set<Ty,Tx>*)(this);
    }

    void do_destroy()
    {
    }


    const data<Ty,Tx>& do_get_data(size_t i)const
    {
      return data_vec.at(i);
    }

    void do_set_data(size_t i,const data<Ty,Tx>& d)
    {
      data_vec.at(i)=d;
    }
  
    size_t do_size()const
    {
      return data_vec.size();
    }
  
    void do_add_data(const data<Ty,Tx>& d)
    {
      data_vec.push_back(d);
    }
  
    void do_clear()
    {
      data_vec.clear();
    }

    bool insert_data(size_t idx,const data<Ty,Tx>& d)
    {
      if(idx<0||idx>data_vec.size())
	{
	  return false;
	}
      data_vec.insert(data_vec.begin()+idx,d);
      return true;
    }

    bool insert_data(size_t idx,size_t n,const data<Ty,Tx>& d)
    {
      if(idx<0||idx>data_vec.size())
	{
	  return false;
	}
      data_vec.insert(data_vec.begin()+idx,n,d);
      return true;
    }
    

    bool erase_data(size_t idx)
    {
      if(idx>=0&&idx<data_vec.size())
	{
	  data_vec.erase(data_vec.begin()+idx);
	  return true;
	}
      return false;
    }

    bool erase_data(size_t beg,size_t end)
    {
      if(beg>=0&&beg<=end&&end<=data_vec.size())
	{
	  data_vec.erase(data_vec.begin()+beg,data_vec.begin()+end);
	  return true;
	}
      return false;
    }

  public:
    shared_table_data_set()
    {}
    
    shared_table_data_set(const shared_table_data_set<Ty,Tx>& rhs)
      :data_vec(rhs.data_vec)
    {}

    shared_table_data_set(const data_set<Ty,Tx>& rhs)
    {
      data_vec.resize(rhs.size());
      for(int i=0;i<data_vec.size();++i)
	{
	  data_vec[i](rhs.get_data(i));
	}
    }

    shared_table_data_set& operator=(const shared_table_data_set<Ty,Tx>& rhs)
    {
      data_vec=rhs.data_vec;
      return *this;
    }

    shared_table_data_set& operator=(const data_set<Ty,Tx>& rhs)
    {
      data_vec.resize(rhs.size());
      for(int i=0;i<data_vec.size();++i)
	{
	  data_vec[i](rhs.get_data(i));
	}
      return *this;
    }

    
  };
}

#endif
//EOF

#include<bint.h>

using base_int_t = uint32_t;

inline std::pair<base_int_t,base_int_t> base_int_add(base_int_t x,base_int_t y,base_int_t carry=0)
{
    uint64_t r=uint64_t(x)+y+carry;
    return std::make_pair(r,r>>32);
}

inline std::pair<base_int_t,base_int_t> base_int_sub(base_int_t x,base_int_t y,base_int_t carry=0)
{
    uint64_t r=uint64_t(x)-y-carry;
    return std::make_pair(r,(r>>32)&1);
}

inline std::pair<base_int_t,base_int_t> base_int_mul(base_int_t x,base_int_t y,base_int_t carry=0)
{
    uint64_t r=uint64_t(x)*y+carry;
    return std::make_pair(r,r>>32);
}

inline std::pair<base_int_t,base_int_t> base_int_divmod(base_int_t x,base_int_t y,base_int_t carry=0)
{
    uint64_t t=uint64_t(x)+(uint64_t(carry)<<32);
    return std::make_pair(t/y,t%y);
}


#include<cstdio>
int main(int argc, char const *argv[]) 
{
    //sub
    printf("sub\n");
    {auto [x,y]=base_int_sub(1,0,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_sub(1,1,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_sub(1,2,0);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_sub(0,0,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_sub(0,0,0);printf("%u;%u\n",x,y);}

    //add
    printf("add\n");
    {auto [x,y]=base_int_add(1,~0,0);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_add(1,~1,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_add(0,0,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_add(1,0,0);printf("%u;%u\n",x,y);}

    //mul
    printf("mul\n");
    {auto [x,y]=base_int_mul(1,0,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_mul(1,3,2);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_mul(1000000000,1000000000,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_mul(~0,~0,~0);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_mul(~0,~0,0);printf("%u;%u\n",x,y);}

    //divmod
    printf("divmod\n");
    {auto [x,y]=base_int_divmod(0,2,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_divmod(0,2,0);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_divmod(65536,2,1);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_divmod(0,2,~0);printf("%u;%u\n",x,y);}
    {auto [x,y]=base_int_divmod(1,2,1);printf("%u;%u\n",x,y);}


    return 0;
}

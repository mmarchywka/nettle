#ifndef MJM_NETTLE_SAVER_H__
#define MJM_NETTLE_SAVER_H__

#include "mjm_globals.h"
#include "mjm_thread_util.h"

//#include "mjm_block_matrix.h"
#include "mjm_instruments.h"
#include "mjm_strings.h"
#include "mjm_string_kvp.h"
#include "mjm_worm_blob.h"
#include "mjm_collections.h"
//#include "mjm_tokenized_collections.h"
#include "mjm_canned_methods.h"

#include "mjm_pawnoff.h"
#include "mjm_strings.h"
#include "mjm_string_kvp.h"
#include "mjm_generic_iterators.h"

#include <iostream>
#include <fstream>


#include <map> 
#include <vector> 
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <fstream>
#include <signal.h>
#include <stdlib.h>
#include <stdint.h>
#include <chrono>


/*
<one line to give the program's name and a brief idea of what it does.>


Conceived and written by Mike Marchywka from 2025 to present.
See dates in individual code pieces as they were 
generated from my wizards. 
Copyright (C) <year> <name of author>


This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of  MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/*
@software{,
  author = {Michael J Marchywka},
  city = {Talking Rock GA 30175 USA},
  title = {},
abstract={},
institution={},
license={Knowledge sir should be free to all },
publisher={Mike Marchywka},
email={marchywka@hotmail.com},
authorid={orcid.org/0000-0001-9237-455X},
  filename={mjm_nettle_saver.h},
  url = {},
  version = {0.0.0},
  date-started={2025-04-09},
}
*/

// Wed 09 Apr 2025 07:21:14 PM EDT
// generated by /home/documents/cpp/scripts/cpputil -classhdr mjm_nettle_saver   
// QUICKCOMPILE  g++  -MMD -MF mjm_nettle_saver.deps  -Wall -Wno-misleading-indentation  -std=gnu++11 -DTEST_MJM_NETTLE_SAVER -I. -I../../mjm/hlib -I../../mjm/num  -gdwarf-3 -O0  -x c++ mjm_nettle_saver.h  -o mjm_nettle_saver.out -lpthread -lreadline

mjm_global_credits::credit __credit__mjm_nettle_saver("mjm_nettle_saver" , "  ");

template <class Tr>
class mjm_nettle_saver 
{
 typedef mjm_nettle_saver Myt;
 typedef typename Tr::IdxTy IdxTy;
 typedef typename Tr::D D;
 typedef typename Tr::StrTy StrTy;
 typedef typename Tr::Ss Ss;
 typedef typename Tr::IsTy IsTy;
 typedef typename Tr::OsTy OsTy;
 typedef typename Tr::Ofs Ofs;
//typedef typename Tr::FlagTy; 
// typedef typename Tr::MyBlock  MyBlock;

// TYPEDEF 
enum { BAD=~0};
//typedef mjm_canned_methods Canned;
typedef mjm_ragged_table Ragged;
typedef Ragged::Line Line;
typedef std::map<StrTy, Ragged> RaggedMap;
typedef std::vector<StrTy> Words;
typedef mjm_string_base_params<Tr> BaseParams;

typedef std::ofstream OfTy;
typedef long int TimeTy;

 // google ai

static TimeTy Now()
{
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Calculate the duration since the epoch
    auto duration = now.time_since_epoch();

    // Convert the duration to seconds (or other units as needed)
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
//    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
return (seconds);
}// Now
static TimeTy  start_time() { static TimeTy x=Now(); return x; } 

// API

public:
mjm_nettle_saver() {Init(); }
mjm_nettle_saver(const StrTy & sin,const IdxTy flags) {Init(sin,flags); }
mjm_nettle_saver(const Ragged & r,const IdxTy start, const IdxTy first,const IdxTy flags ) {Init(r,start,first,flags);}

void load(const StrTy & sin,const IdxTy flags) {Init(sin,flags); }
void load(const Ragged & r,const IdxTy start, const IdxTy first,const IdxTy flags ) {Init(r,start,first,flags);}
void save(const StrTy & fn,const StrTy &s) {Save(fn,s); }
IdxTy out(const int s1, const int s2, const char * p, const IdxTy n) { return Out(s1,s2,p,n); } 
IdxTy out(const StrTy & fn, const char * p, const IdxTy n) { return OutFix(fn,p,n); } 
StrTy xxx_test(const StrTy & sin, const IdxTy flags) 
{ return XXX_test(sin,flags); } 
~mjm_nettle_saver() {}
StrTy dump(const IdxTy flags=0) { return Dump(flags); }
private:
int myatoi(const StrTy & s )const   { return mjm_canned_methods::myatoi(s.c_str()); }
int myatoi(const char * c) const  { return mjm_canned_methods::myatoi(c); }
static bool Bit(const IdxTy f, const IdxTy b) { return  ((f>>b)&1)!=0; }
// should loop over map now 
static void Set(IdxTy& f, const IdxTy b,const bool x) //const  
    { if (x) f|=(1<<b); else f&=((~1)<<b); }
StrTy Dump(const IdxTy flags=0) {Ss ss;  return ss.str(); }
typedef typename mjm_thread_util<Tr>::mutex_vector MutexVector;

enum { MAP_MU=0 , MU_SZ};
mutable MutexVector m_mutex_vector;
void EnterSerial(const IdxTy i)const  {  m_mutex_vector.enter_serial(i ); }
void ExitSerial(const IdxTy i)const  {  m_mutex_vector.exit_serial(i ); }
//m_mutex_vector = MutexVector(MU_SZ);


void Save(const StrTy & fn,const StrTy &s) {
// std::ofstream ofs(fn);

 } // Save
StrTy XXX_test(const StrTy & sin, const IdxTy flags) 
{
StrTy sout="";
MM_ERR(MMPR3(sin,flags,sout))
BaseParams kvp(sin);

return sout;
} // XXX_test
enum { OFLAGS=std::ios::binary| std::ios::app};
IdxTy Out(const int s1, const int s2, const char * p, const IdxTy n)
{
//MM_ERR(MMPR4(s1,d2,n,__FUNCTION__))
if (n==0) return 0; 
Ss ss;
ss<<"nettle_dump_"<<start_time()<<"_"<<s1<<"_"<<s2<<".raw";
//StrTy fn="foo.out"; 
StrTy fn=ss.str(); 
return Out(fn,p,n);
}
IdxTy OutFix(const StrTy & id, const char * p, const IdxTy n)
{
//MM_ERR(MMPR4(s1,d2,n,__FUNCTION__))
if (n==0) return 0; 
Ss ss;
ss<<"nettle_dump_"<<(start_time()%1000000)<<"_"<<id<<".raw";
//StrTy fn="foo.out"; 
StrTy fn=ss.str(); 
return Out(fn,p,n);
}


IdxTy Out(const StrTy & fn, const char *p, const IdxTy n)
{
OfTy os;
os.open(fn.c_str(),(std::ios_base::openmode)OFLAGS);
if (os.is_open())
{
os.write(p,n);
if (os.good()) return 0;
//MM_ERR(" fail write output on "<<MMPR4(fn,os.eof(),os.bad(),os.fail())<<MMPR3(n,s1,s2))
MM_ERR(" fail write output on "<<MMPR4(fn,os.eof(),os.bad(),os.fail())<<MMPR(n))

}
else
{
MM_ERR(" fail output on "<<MMPR4(fn,os.eof(),os.bad(),os.fail())<<MMPR(n))
}
return 0;
} // Out
void Init(const Ragged & r, const IdxTy start=0, const IdxTy first=0, const IdxTy flags=0  )
{
Init();
const IdxTy sz=r.size();
for(IdxTy i=start; i<sz; ++i)
{
//const Line & l=r[i];
//const IdxTy len=l.size();


}  // i 

} // Init 
void Init(const StrTy  & sin,const IdxTy flags =0  )
{
Init();
BaseParams kvp(sin);
} // Init 

void Init()
{


} // Init



// MEMBERS



}; // mjm_nettle_saver

//////////////////////////////////////////////

template <class Tr>
class mjm_nettle_saver_map : public std::map<typename Tr::StrTy, mjm_nettle_saver< Tr > >  
{
 typedef mjm_nettle_saver_map Myt;
typedef typename std::map<typename Tr::StrTy, mjm_nettle_saver< Tr> >   Super;
 typedef typename Tr::IdxTy IdxTy;
 typedef typename Tr::D D;
 typedef typename Tr::StrTy StrTy;
 typedef typename Tr::Ss Ss;
 typedef typename Tr::IsTy IsTy;
 typedef typename Tr::OsTy OsTy;
 typedef typename Tr::Ofs Ofs;
//typedef typename Tr::FlagTy; 
// typedef typename Tr::MyBlock  MyBlock;
public:
mjm_nettle_saver_map() {}
StrTy dump(const IdxTy flags=0) { return Dump(flags); }
private:
bool Bit(const IdxTy f, const IdxTy b) const  { return  ((f>>b)&1)!=0; }
// should loop over map now 
//StrTy Dump(const IdxTy flags=0) {Ss ss;  return ss.str(); }
typedef typename mjm_thread_util<Tr>::mutex_vector MutexVector;

enum { MAP_MU=0 , MU_SZ};
mutable MutexVector m_mutex_vector;
void EnterSerial(const IdxTy i)const  {  m_mutex_vector.enter_serial(i ); }
void ExitSerial(const IdxTy i)const  {  m_mutex_vector.exit_serial(i ); }
//m_mutex_vector = MutexVector(MU_SZ);


//StrTy dump(const IdxTy flags=0) { return Dump(flags); }

private:

void Init()
{


}

StrTy Dump(const IdxTy flags=0)
{
Ss ss;
MM_LOOP(ii,(*this))
{
ss<<(*ii).first<<CRLF;
ss<<(*ii).second.dump()<<CRLF;


}
return ss.str();
// return Dump(flags); 

}




private:

}; // mjm_nettle_saver_map




////////////////////////////////////////////
#ifdef  TEST_MJM_NETTLE_SAVER
class Tr {
public:
// typedef mjm_string_picker Myt;
 typedef unsigned int IdxTy;
 typedef double  D;
 typedef std::string StrTy;
 typedef std::stringstream Ss;
 typedef std::istream  IsTy;
 typedef std::ostream  OsTy;
 typedef std::ofstream  Ofs;
// typedef typename Tr::MyBlock  MyBlock;
}; // 


#include "mjm_instruments.h"
#include "mjm_cli_ui.h"
typedef Tr::StrTy StrTy;
typedef Tr::IdxTy IdxTy;

template <class Tt> class tester_ {
typedef tester_<Tt> Myt;
typedef mjm_cli_ui<Myt> Cli;
//typedef tester Myt;
//typedef mjm_cli_ui<Myt> Cli;
typedef std::map<StrTy, StrTy> LocalVar;

typedef CommandInterpretterParam Cip ;
typedef void (Myt:: * CmdFunc)(Cip &, LocalVar &  ) ;
typedef std::map<StrTy, CmdFunc> CmdMap;
typedef std::vector<StrTy> Choices;
//typedef void (Myt:: * CompleteFunc) ( Cli::list_type & choices,  const char * cmd, const char * frag);
typedef void (Myt:: * CompleteFunc) ( Choices & choices,  const char * cmd, const char * frag);
typedef std::map<StrTy, CompleteFunc> CompMap;

public:
 //void cli_cmd( Cli::list_type & choices,  const char * frag)
 void cli_cmd( Choices & choices,  const char * frag)
{
const IdxTy nfrag=strlen(frag);
MM_LOOP(ii,m_cmd_map)
{
const StrTy & v=(*ii).first;
if (strncmp(v.c_str(),frag,nfrag)==0)  choices.push_back(v);
}
}

 //void cli_param( Cli::list_type & choices,  const char * _cmd, const char * frag)
 void cli_param( Choices & choices,  const char * _cmd, const char * frag)
{
MM_ERR("cli_param"<<MMPR2(_cmd,frag))
//const StrTy cmd=CliTy::word(StrTy(_cmd),0);
//auto ii=m_comp_map.find(cmd);
//if ( ii!=m_comp_map.end()) ((this)->*(*ii).second)(choices,cmd.c_str(),frag);
}

CmdMap m_cmd_map;


 }; // tester_
typedef tester_< mjm_nettle_saver <Tr>  > tester;

typedef mjm_cli_ui<tester> Cli;


typedef Tr::Ss Ss;

#define CI(n) atoi(cip.wif(n).c_str()) 

void about()
{
Ss ss;
ss<<" MJM_NETTLE_SAVER "<<__DATE__<<" "<<__TIME__<<CRLF;
MM_MSG(ss.str())

}
typedef mjm_ragged_table Ragged;

#define CIP(n) atoi(cip.wif(n).c_str())
#define CFP(n) atof(cip.wif(n).c_str())

int main(int argc,char **args)
{
about();
typedef mjm_nettle_saver<Tr>  Myt;
//Myt x(argc,args);
Myt x;

//if (!x.done()) x.command_mode();
Cli cli;
tester tester;
CommandInterpretter li(&std::cin);
li.push(args,argc);
cli.set_target(tester);
cli.set_command_handler(&tester::cli_cmd);
cli.set_param_handler(&tester::cli_param);
cli.activate();
li.set_split(1,' ');
while (li.nextok())
{
const IdxTy sz=li.size();
if (sz<1) continue;
const StrTy cmd=li.word(0);
if (cmd=="") continue;
if (cmd=="about"){ about();  continue; } 
CommandInterpretterParam  cip(li);

if (cmd=="loadragged") {
 	const IdxTy start=atoi(cip.wif(2).c_str()); 
	const IdxTy first=atoi(cip.wif(3).c_str()); 
	const IdxTy flags=atoi(cip.wif(4).c_str()); 
Ragged r; r.load(cip.p1); x.load(r,start,first,flags); }
if (cmd=="load") {x.load(cip.p1,atoi(cip.p2.c_str())); }
if (cmd=="save") {x.save(cip.p1,cip.p2); }
if (cmd=="test") {StrTy xxx=x.xxx_test(cip.p1,CIP(2)); MM_ERR(MMPR(xxx))  }
if (cmd=="quit") break;
// NB this does not work in gneral when errors are disabled
//if (cmd=="dump") { MM_ERR(x.dump()) }
if (cmd=="dump") { auto wtf=x.dump();  MM_ERR(wtf) }
//else if (cmd=="load") { x.load(li.words(),1); }
//else if (cmd=="clear") { x.clear(); }

} // nextok

//if (!x.done()) x.command_mode();
return 0;
}

#endif // main

#endif // MJM_NETTLE_SAVER_H__ 

// SWIG file

%{
#include "otmorris/Morris.hxx"
%}

%include Morris_doc.i

%include otmorris/Morris.hxx
namespace OTMORRIS { %extend Morris { Morris(const Morris & other) { return new OTMORRIS::Morris(other); } } }

#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CORE_LIBRARY)
#  define WIND_CORE_API Q_DECL_EXPORT
#else
#  define WIND_CORE_API Q_DECL_IMPORT
#endif

#endif // CORE_GLOBAL_H

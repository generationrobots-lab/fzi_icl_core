// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of FZIs ic_workspace.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE folder in the top
// directory of the source code.
//
// © Copyright 2016 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2009-01-20
 *
 * \brief   Contains icl_core::thread::SemaphoreImpl
 *
 * \b icl_core::thread::SemaphoreImpl
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_SEMAPHORE_IMPL_H_INCLUDED
#define ICL_CORE_THREAD_SEMAPHORE_IMPL_H_INCLUDED

#include <icl_core/Noncopyable.h>
#include <icl_core/TimeSpan.h>
#include <icl_core/TimeStamp.h>

namespace icl_core {
namespace thread {

class SemaphoreImpl : protected virtual icl_core::Noncopyable
{
public:
  virtual ~SemaphoreImpl() {}
  virtual void post() = 0;
  virtual bool tryWait() = 0;
  virtual bool wait() = 0;
  virtual bool wait(const icl_core::TimeSpan& timeout) = 0;
  virtual bool wait(const icl_core::TimeStamp& timeout) = 0;
};

}
}

#endif

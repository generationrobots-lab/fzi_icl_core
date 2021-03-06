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
 */
//----------------------------------------------------------------------
#include "SemaphoreImplPosix.h"

#include <errno.h>

namespace icl_core {
namespace logging {

SemaphoreImplPosix::SemaphoreImplPosix(size_t initial_value)
  : m_semaphore(0)
{
  m_semaphore = new sem_t;
  sem_init(m_semaphore, 0, initial_value);
}

SemaphoreImplPosix::~SemaphoreImplPosix()
{
  if (m_semaphore)
  {
    sem_destroy(m_semaphore);
    delete m_semaphore;
    m_semaphore = 0;
  }
}

void SemaphoreImplPosix::post()
{
  sem_post(m_semaphore);
}

bool SemaphoreImplPosix::wait()
{
  int res = sem_wait(m_semaphore);
  return (res == 0);
}

}
}

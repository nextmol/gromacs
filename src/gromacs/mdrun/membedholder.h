/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 2020, by the GROMACS development team, led by
 * Mark Abraham, David van der Spoel, Berk Hess, and Erik Lindahl,
 * and including many others, as listed in the AUTHORS file in the
 * top-level source directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */
/*! \internal
 * \brief Encapsulates membed methods
 *
 * \author Joe Jordan <ejjordan@kth.se>
 * \ingroup module_mdrun
 */
#ifndef GMX_MDRUN_MEMBEDHOLDER_H
#define GMX_MDRUN_MEMBEDHOLDER_H

#include <cstdio>

#include "gromacs/utility/real.h"

struct gmx_membed_t;
struct gmx_mtop_t;
struct t_commrec;
struct t_filenm;
struct t_inputrec;
class t_state;

namespace gmx
{

/*! \brief Membed SimulatorBuilder parameter type.
 *
 * Does not (yet) encapsulate ownership semantics of resources. Simulator is
 * not (necessarily) granted ownership of resources. Client is responsible for
 * maintaining the validity of resources for the life time of the Simulator,
 * then for cleaning up those resources.
 */
class MembedHolder
{
public:
    explicit MembedHolder(int nfile, const t_filenm fnm[]);
    MembedHolder(MembedHolder&& holder) noexcept;
    MembedHolder& operator=(MembedHolder&& holder) noexcept;

    MembedHolder(const MembedHolder&) = delete;
    MembedHolder& operator=(const MembedHolder&) = delete;

    ~MembedHolder();

    [[nodiscard]] bool doMembed() const { return doMembed_; }

    void initializeMembed(FILE*          fplog,
                          int            nfile,
                          const t_filenm fnm[],
                          gmx_mtop_t*    mtop,
                          t_inputrec*    inputrec,
                          t_state*       state,
                          t_commrec*     cr,
                          real*          cpt);

    gmx_membed_t* membed();

private:
    gmx_membed_t* membed_   = nullptr;
    bool          doMembed_ = false;
};

} // namespace gmx

#endif // GMX_MDRUN_MEMBEDHOLDER_H
/* define USE_MPE if you want MPE logging 
 *
 * you then need to link with the appropriate libraries
 * that come with the mpich distribution (can be found in the
 * mpe subdirectory */
/* #define USE_MPE */

/* define BARRIERS if you want to have extra MPI_Barriers
 * in the code which might help analyzing the MPE logfiles 
 */
/* #define BARRIERS */
#ifdef BARRIERS
#define GMX_BARRIER(communicator) MPI_Barrier(communicator)
#else
#define GMX_BARRIER(communicator)
#endif

#ifdef USE_MPE
#define GMX_MPE_LOG(event) MPE_Log_event(event, 0, "")
#else
#define GMX_MPE_LOG(event)
#endif

#ifdef USE_MPE
#include "mpe.h"
     /* Define MPE logging events here */
     /* General events */
     int ev_timestep1,               ev_timestep2;
     int ev_ns_start,                ev_ns_finish;
     int ev_calc_bonds_start,        ev_calc_bonds_finish;
     int ev_send_coordinates_start,  ev_send_coordinates_finish;
     int ev_update_fr_start,         ev_update_fr_finish;
     int ev_clear_rvecs_start,       ev_clear_rvecs_finish;
     int ev_output_start,            ev_output_finish;
     int ev_update_start,            ev_update_finish;     
     int ev_force_start,             ev_force_finish;
     int ev_do_fnbf_start,           ev_do_fnbf_finish;
     
     /* Shift related events*/
     int ev_shift_start,             ev_shift_finish;     
     int ev_unshift_start,           ev_unshift_finish;     
     int ev_mk_mshift_start,         ev_mk_mshift_finish;
     
     /* PME related events */
     int ev_pme_start,               ev_pme_finish;
     int ev_spread_on_grid_start,    ev_spread_on_grid_finish;
     int ev_sum_qgrid_start,         ev_sum_qgrid_finish;
     int ev_gmxfft3d_start,          ev_gmxfft3d_finish;
     int ev_solve_pme_start,         ev_solve_pme_finish;
     int ev_gather_f_bsplines_start, ev_gather_f_bsplines_finish;
     int ev_reduce_start,            ev_reduce_finish;
     int ev_rscatter_start,          ev_rscatter_finish;
     int ev_alltoall_start,          ev_alltoall_finish;
     int ev_pmeredist_start,         ev_pmeredist_finish;
     int ev_init_pme_start,          ev_init_pme_finish;
     int ev_global_stat_start,       ev_global_stat_finish;
     int ev_sum_lrforces_start,      ev_sum_lrforces_finish;
     int ev_virial_start,            ev_virial_finish;
     int ev_sort_start,              ev_sort_finish;
     int ev_sum_qgrid_start,         ev_sum_qgrid_finish;
     
     /* Essential dynamics related events */
     int ev_edsam_start,             ev_edsam_finish;
     int ev_get_coords_start,        ev_get_coords_finish;
     int ev_ed_apply_cons_start,     ev_ed_apply_cons_finish;
     int ev_fit_to_reference_start,  ev_fit_to_reference_finish;
#endif

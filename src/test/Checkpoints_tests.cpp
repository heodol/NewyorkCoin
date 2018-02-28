//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p10000 = uint256("0x132e14f7d82b659329ac95300413beba2c00f9e3d1b137533a093fce18d3febd");
    uint256 p100000 = uint256("0x495da2e0cffa0ad6c0fe83c2678e2c714e024ed009abcdb24728d306b599232f");
	uint256 p500000 = uint256("0xb9db8c11eacd9921fb09ad149fc9b7cf41e429e759f8304043398d7ed1067952");
	uint256 p1000000 = uint256("0x157fc4df4e7594abae3487c554bbea91cd70a1014faf7ae7b5d3ee4d9da80226");
	uint256 p1500000 = uint256("0xc185fa9930597d386977969894cecaec21547589efdf756d533824f86244cda1");
	uint256 p2000000 = uint256("0xde3f57919d2048c915e369642f6216aed78f5f0c9a59e45763a09d97f483fa2a");
	uint256 p2500000 = uint256("0x93896d159dbc68e7ac109f4fa7e05365cbb08d78b6fe3957c4a330a878bf2e2a");
	uint256 p3000000 = uint256("0x66e6dcb49370062537c1f6abf655ffbbc53ba4851ef00081aa2e4be1e2903ba7");
	uint256 p3500000 = uint256("0x3f1a97f68ce8eaf38fc0c56868b3eb98ccb67d14bff4e78afb91d82cba853ddf");
	
    BOOST_CHECK(Checkpoints::CheckBlock(10000, p10000));
    BOOST_CHECK(Checkpoints::CheckBlock(100000, p100000));
	BOOST_CHECK(Checkpoints::CheckBlock(500000, p500000));
	BOOST_CHECK(Checkpoints::CheckBlock(1000000, p1000000));
	BOOST_CHECK(Checkpoints::CheckBlock(1500000, p1500000));
	BOOST_CHECK(Checkpoints::CheckBlock(2000000, p2000000));
	BOOST_CHECK(Checkpoints::CheckBlock(2500000, p2500000));
	BOOST_CHECK(Checkpoints::CheckBlock(3000000, p3000000));
	BOOST_CHECK(Checkpoints::CheckBlock(3500000, p3500000));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(10000, p3500000));
    BOOST_CHECK(!Checkpoints::CheckBlock(3500000, p1500000));
	BOOST_CHECK(!Checkpoints::CheckBlock(1500000, p10000));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(10000+1, p100000));
    BOOST_CHECK(Checkpoints::CheckBlock(1500000+1, p10000));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 120000);
}    

BOOST_AUTO_TEST_SUITE_END()

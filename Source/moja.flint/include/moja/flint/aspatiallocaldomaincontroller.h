#ifndef MOJA_FLINT_ASPATIALLOCALDOMAINCONTROLLER_H_
#define MOJA_FLINT_ASPATIALLOCALDOMAINCONTROLLER_H_

#include "moja/flint/localdomaincontrollerbase.h"
#include "moja/flint/spinuplandunitcontroller.h"

namespace moja {
namespace datarepository {
class LandUnitInfo;
class AspatialTileInfo;
class AspatialTileInfoCollection;
}  // namespace datarepository
}  // namespace moja

namespace moja {
namespace flint {

class FLINT_API AspatialLocalDomainController final : public LocalDomainControllerBase {
  public:
   AspatialLocalDomainController() : _spinupLandUnitController(_landUnitController), _runSpinUp(false) {}
   ~AspatialLocalDomainController() = default;

   status configure(const configuration::Configuration& config) override;
   status run() override;

   void run(moja::datarepository::AspatialTileInfo& tile);
   status startup() override;
   status shutdown() override;

  private:
   std::unique_ptr<moja::datarepository::AspatialTileInfoCollection> _landscape;
   SpinupLandUnitController _spinupLandUnitController;
   NotificationCenter _spinupNotificationCenter;
   bool _runSpinUp;
   std::shared_ptr<SequencerModuleBase> _spinupSequencer;
   LocalDomainControllerBase::ModuleMap _spinupModules;
   IVariable* _luId;

   status run(const moja::datarepository::LandUnitInfo& lu);
};

}  // namespace flint
}  // namespace moja

#endif  // MOJA_FLINT_ASPATIALLOCALDOMAINCONTROLLER_H_
